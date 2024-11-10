@MainPage C++ 2d Physics Engine

[gitHubProject]: https://www.github.com

# C++ 2d Physics Engine

By Lucas Capp

### Description

This is a Physics Engine for 2d C++ applications and is a light weight tool designed for fairly simple C++ projects.  
Download the folder from github [here][gitHubProject].  

### Overview

The physics engine works as follows:

+ Class called _ObjectManager_ manages objects in the simulation.
  + __stores, removes, adds, finds, and loops through__ objects to update them.
+ Class called _Object_ represents any object or entity in your simulation.
  + Contains members like __Velocity__, __Acceleration__, __Mass__, and more.
  + Contains members based on the given shape.
  + Updates it's position given a delta time.
+ Class called _Rectangle_ represents a rectangular game object.
  + Contains member called plane.
+ Class called _Circle_ represents a circular game object.
  + Contains members like radius and center.
+ Class called _Collision manager_ manages collisions
  + Holds a _reference_ to objects in an instance of and __ObjectManager__ class
  + Finds collisions, then resolves collisions my changing positions and other attributes of game objects.
+ File called _PhysicsEquations.h_ holds functions that represent physics equations.
  + Contains functions like __findVelocity(deltaTime, Velocity, Acceleration)__, or __findForce(Mass, Acceleration)__

<br>

> Note, most if not all classes contain  
> public getters and setters for almost  
> all class members.

<br>

