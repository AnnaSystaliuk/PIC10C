//
//  GameViewController.swift
//  Tetris
//
//  Created by Anna on 5/21/17.
//  Copyright © 2017 Anna All rights reserved.
//

import UIKit
import SpriteKit
import GameplayKit

class GameViewController: UIViewController, MainDelegate, UIGestureRecognizerDelegate {
    @IBOutlet weak var speedup: UILabel!
    
    var scene: GameScene!
    var mainView:Main!
    var panPointReference:CGPoint?
    var score = 0
    @IBOutlet weak var scoreLabel: UILabel!


    override func viewDidLoad() {
        super.viewDidLoad()
        
        let skView = view as! SKView
        skView.isMultipleTouchEnabled = false
        
        scene = GameScene(size: skView.bounds.size)
        scene.scaleMode = .aspectFit
        
        scene.tick = didTick
        
        mainView = Main()
        mainView.delegate = self
        mainView.beginGame()
        scoreLabel.text = String(score)
        skView.presentScene(scene)
        
    }

    override var shouldAutorotate: Bool {
        return true
    }

    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        if UIDevice.current.userInterfaceIdiom == .phone {
            return .allButUpsideDown
        } else {
            return .all
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

    override var prefersStatusBarHidden: Bool {
        return true
    }
    @IBAction func didPan(_ sender: Any) {
        print("PAN")
        let currentPoint = (sender as! UIPanGestureRecognizer).translation(in: self.view)
        if let originalPoint = panPointReference {
            if abs(currentPoint.x - originalPoint.x) > (BlockSize * 0.9) {
                if (sender as! UIPanGestureRecognizer).velocity(in: self.view).x > CGFloat(0) {
                    mainView.moveShapeRight()
                    panPointReference = currentPoint
                } else {
                    mainView.moveShapeLeft()
                    panPointReference = currentPoint
                }
            }
        } else if (sender as AnyObject).state == .began {
            panPointReference = currentPoint
        }
    }
    
    @IBAction func didSwipe(_ sender: Any) {
        print("SWIPE")
        mainView.dropShape()
    }
    

    @IBAction func didTap(_ sender: Any) {
        print("TAP")
        mainView.rotateShape()
    }
    
    func didTick() {
        mainView.letShapeFall()
    }
    
    
    func gestureRecognizer(_ gestureRecognizer: UIGestureRecognizer, shouldRecognizeSimultaneouslyWith otherGestureRecognizer: UIGestureRecognizer) -> Bool {
        return true
    }
    

    func gestureRecognizer(_ gestureRecognizer: UIGestureRecognizer, shouldBeRequiredToFailBy otherGestureRecognizer: UIGestureRecognizer) -> Bool {
        if gestureRecognizer is UISwipeGestureRecognizer {
            if otherGestureRecognizer is UIPanGestureRecognizer {
                return true
            }
        } else if gestureRecognizer is UIPanGestureRecognizer {
            if otherGestureRecognizer is UITapGestureRecognizer {
                return true
            }
        }
        return false
    }
    
    
    func nextShape() {
        
        scoreLabel.text = String(score)

        
        print("nextShape called")
        let newShapes = mainView.newShape()
        guard let fallingShape = newShapes.fallingShape else {
            return
        }
        self.scene.addPreviewShapeToScene(shape: newShapes.nextShape!) {}
        self.scene.movePreviewShape(shape: fallingShape) {

            self.view.isUserInteractionEnabled = true
            self.scene.startTicking()
        }
    }
    
    func gameDidBegin(Main: Main) {
        if mainView.nextShape != nil && mainView.nextShape!.blocks[0].sprite == nil {
            scene.addPreviewShapeToScene(shape: mainView.nextShape!) {
                self.nextShape()
            }
        } else {
            nextShape()
        }
    }
    
    func gameDidEnd(Main: Main) {
        view.isUserInteractionEnabled = false
        scene.stopTicking()
        scene.animateCollapsingLines(linesToRemove: mainView.removeAllBlocks(), fallenBlocks: mainView.removeAllBlocks()) {
            self.mainView.beginGame()
        }
    }
    
    func gameDidLevelUp(Main: Main) {
    }
    
    func gameShapeDidDrop(Main: Main) {
        
        scene.stopTicking()
        scene.redrawShape(shape: mainView.fallingShape!) {
            self.mainView.letShapeFall()
        }

        
    }
    
    func gameShapeDidLand(Main: Main) {
        scene.stopTicking()

        self.view.isUserInteractionEnabled = false
        let removedLines = mainView.removeCompletedLines()
        if removedLines.linesRemoved.count > 0 {
            UIView.animate(withDuration: 1.0, delay: 0.0, options: UIViewAnimationOptions.curveEaseIn, animations: {
                self.speedup.alpha = 1.0
            }, completion: { (done:Bool) in
                self.speedup.alpha = 0.0
            })
            score = score + removedLines.linesRemoved.count;
            scene.animateCollapsingLines(linesToRemove: removedLines.linesRemoved, fallenBlocks:removedLines.fallenBlocks) {

                self.gameShapeDidLand(Main: self.mainView)
            }
            
        } else {
            nextShape()
        }

    }
    
    func gameShapeDidMove(Main: Main) {
        scene.redrawShape(shape: mainView.fallingShape!) {}
    }
}
