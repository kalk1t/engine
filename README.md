# Engine

this engine is going to be a windows platform engine for 3d games build/compiled and debugged in MVS

here are the main features i will add to this engine time by time

each added feature will be marked ✅

# 1. Core Engine Infrastructure

Platform Abstraction Layer

High-resolution timer, threads, mutexes

Memory Management

Custom allocators (stack, pool, arena, free-list)

Math Library (vec2/vec3/vec4, mat3/mat4) 

Logging & Assertions

Macro-driven logs (levels, file/line), fatal-error hooks

File System

Cross-platform file I/O, path handling, directory watching

Event & Messaging System

Typed events, subscribers, message queue

Resource Management

Reference-counted handles, hot-reload support

# 2. Rendering Subsystem

Graphics Context & Swap Chain

Shader Manager

GLSL/HLSL compile, reflection, uniform/attribute binding

Mesh & Material System

Vertex/index buffers, input layouts, material properties

Texture Loader

Image decoding (PNG, JPG)i

Camera & Culling

View/projection, frustum tests

Lighting & Shadows

Post-Processing Pipeline

Framebuffers, fullscreen passes, tone mapping

# 3. Input System

Keyboard & Mouse

Gamepad/Joystick

Input Mapping

Action-to-key bindings, rebinding UI

# 4. Audio Subsystem

Low-Level Audio API

Sound device enumeration, mixing buffer

Playback & Mixer

One-shots, streaming music, channel groups

3D Spatialization

Attenuation, Doppler effect

# 5. Scene & Entity Management

Entity Component System (ECS) or Scene Graph

Transform Hierarchy

Serialization & Prefabs

# 6. Physics & Collision

Collision Primitives (AABB, sphere, plane)

Broadphase (grid, quadtree/octree)

Narrowphase (GJK, SAT)

Rigid-Body Solver (Euler/Verlet integrator, contact resolution)

# 7. Animation System

Keyframed Transforms

Skeletal Animation (bone palettes, skinning)

Tweening/Curve Interpolation

# 8. UI & Debug Tools

Immediate-Mode GUI (your own IMGUI)

In-Engine Debug Overlay (FPS, draw calls, scene inspector)

Console & Profiler Hooks

# 9. Scripting & Gameplay Logic

Embedded VM or DSL (you could roll a tiny bytecode interpreter)

Bindings for engine APIs (entities, resources, events)

Hot-Reloading of scripts

# 10. Networking 

Socket Layer (UDP/TCP abstraction)

Packet Serialization (endianness, checksums)

High-Level API (RPC, state sync)

# 11. Tooling & Editors

Level/Scene Editor (standalone or built into the engine)

Material/Shader Editor (live-edit shader code)

Asset Import Pipeline (model, texture, audio converters)

Build & Packaging Scripts




