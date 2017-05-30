#!/afs/cats.ucsc.edu/courses/cmps112-wm/usr/smalltalk/bin/gst -f

nl := Character nl.
tb := Character tab asString.
|inputFile|

dArg:= false. "Debug information is printed for the benefit of the application
author. Exact details are not specified."
tArg:= false. "The compression algorithm is activated, and the decoding tree
is printed to the standard output. The output filename may not be specified."
cArg:= false. "The input file is compressed and written to the output file,
if specified, or to the standard output, if not."
uArg:= false. "The input file is assumed to be compressed, and is uncompressed,
written to the output file, if specified, or to the standard output, if not."
argumentsCount:= 0.

"Zero Array"
Object subclass: ZeroArray [
|theArray|
  ZeroArray class >> new [
    self shouldNotImplement.
  ]
  ZeroArray class >> new: size [
  |result|
    result := super new.
    result init: size.
    ^ result
  ]
  init: size [
    theArray := Array new: size.
  ]
  size [
    ^ theArray size.
  ]
  at: index [
    ^ theArray at: index + 1.
  ]
  at: index put: value [
    ^ theArray at: index + 1 put: value.
  ]
  incr: index [
    (self at: index) isNil
    ifTrue: [ self at: index put: 0].
    self at: index put: (self at: index) + 1.
  ]
  keysAndValuesDo: aBlock [
    (0 to: (self size) - 1) do: [:index |
    aBlock value: index value: (self at: index).
    ]
  ]
].

freqtable:= ZeroArray new: 257.
freqtable at:256 put:1.

"Read arguments"
Smalltalk arguments: '-d -t -c -u'
do: [:argument :rest |
  (argument = $d) ifTrue:[
    dArg:= true.
  ].
  (argument = $t) ifTrue:[
    tArg:= true.
  ].
  (argument = $c) ifTrue:[
    cArg:= true.
  ].
  (argument = $u) ifTrue:[
    uArg:= true.
  ].
  (rest = nil) ifFalse:[
    (argumentsCount = 0) ifTrue: [
    (dArg = true) ifTrue: [stdout << 'Opening Input File: ' << rest << nl.].
    inputFile := FileStream open: rest mode: FileStream read.

    ]ifFalse: [
    (dArg = true) ifTrue: [stdout << 'Opening Output File: ' << rest << nl.].
    ].
    argumentsCount:= argumentsCount + 1.
  ].
].

"Tree as provided"
Object subclass: Leaf [
   |char count isLeaf|
   char [^ char]
   count [^ count]
   isLeaf [^ isLeaf]

   Leaf class >> new [
      self shouldNotImplement
   ]

   Leaf class >> new: aChar count: aCount [
      |result|
      result := super new.
      result setChar: aChar andCount: aCount.
      ^ result
   ]

   setChar: aChar andCount: aCount [
      char := aChar.
      count := aCount.
      isLeaf := true.
   ]

   <= other [
      ^ (count < other count)
      | ((count = other count) & (char <= other char))
   ]

   printBase: aStream [
      ^ aStream << self class << '(' << char << ',' << count
   ]

   printOn: aStream [
      (self printBase: aStream) << ')'.
   ]

   inorder: visitor prefix: string [
      visitor value: char value: string.
   ]

   postorder: visitor [
      visitor  value:char value: isLeaf.
   ]
]

Leaf subclass: Tree [
   |left right|

   Tree class >> new: aChar count: aCount [
      self shouldNotImplement
   ]

   Tree class >> new: aChar count: aCount left: aLeft right: aRight [
      |result|
      result := super new: aChar count: aCount.
      result setLeft: aLeft andRight: aRight.
      ^ result
   ]

   setLeft: aLeft andRight: aRight [
      left := aLeft.
      right := aRight.
      isLeaf := false.
   ]

   left  [ ^ left]
   right [ ^ right]

   printOn: aStream [
      (self printBase: aStream) << ',' << left << ',' << right << ')'.
   ]

   inorder: visitor prefix: string [
      left inorder: visitor prefix: string, '0'.
      right inorder: visitor prefix: string, '1'.
   ]

   postorder: visitor[
      left postorder: visitor .
      right postorder: visitor .
      visitor value: char value:isLeaf.
   ]
]

"Open Inputfile"
[inputFile atEnd not] whileTrue: [
    |item|
    item := inputFile next asInteger.
    "stdout << item << nl."
    freqtable incr: item.
].

"Help print Frequency for debug"
Character extend [
   isPrint [
      ^ (Character space <= self) & (self <= $~)
   ]
   visible [
      self isPrint ifTrue: [^ self asString]
                   ifFalse: [^ self asInteger printStringRadix: 8]
   ]
]

"Print Frequency for debug"
freqtable keysAndValuesDo: [:key :value |
   (value notNil and: [value > 0]) ifTrue:
   [([key asCharacter visible] ~= 8r400)ifTrue: [stdout << 'freq[' <<  key asCharacter visible << '] = ' << value << nl.]
   ifFalse: [stdout << 'freq[' <<  'EOF' << '] = ' << value << nl.].].
 ].
