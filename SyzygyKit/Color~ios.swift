//
//  Color~ios.swift
//  SyzygyKit
//
//  Created by Dave DeLong on 7/6/18.
//  Copyright © 2018 Syzygy. All rights reserved.
//

import Foundation

public typealias PlatformColor = UIColor

public extension PlatformColor {
    
    public static let defaultSelectionColor: PlatformColor = UIColor.blue
    
}

public extension Color {
    
    public var color: UIColor { return UIColor(cgColor: rawColor) }
    public init(color: UIColor) { self.rawColor = color.cgColor }
    
}