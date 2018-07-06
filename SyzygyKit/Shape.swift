//
//  Shape.swift
//  SyzygyKit
//
//  Created by Dave DeLong on 1/17/18.
//  Copyright © 2018 Syzygy. All rights reserved.
//

import Foundation

public struct Shape {
    private let builder: (CGRect) -> BezierPath
    
    public init(builder: @escaping (CGRect) -> BezierPath) {
        self.builder = builder
    }
    
    public func bezierPath(in rect: CGRect) -> BezierPath { return builder(rect) }
}

public extension Shape {
    
    static let circle = Shape { rect in
        let shortestSide = min(rect.width, rect.height)
        let xOffset = rect.width - shortestSide
        let yOffset = rect.height - shortestSide
        let square = CGRect(x: xOffset, y: yOffset, width: shortestSide, height: shortestSide)
        return BezierPath(ovalIn: square)
    }
    
    static let oval = Shape { BezierPath(ovalIn: $0) }
    
    static let square = Shape { rect in
        let shortestSide = min(rect.width, rect.height)
        let xOffset = rect.width - shortestSide
        let yOffset = rect.height - shortestSide
        let square = CGRect(x: xOffset, y: yOffset, width: shortestSide, height: shortestSide)
        return BezierPath(rect: square)
    }
    
    static let rectangle = Shape { BezierPath(rect: $0) }
    
//    static let star = Shape { BezierPath(starShapeIn: $0) }
}
