# miniRT

A CPU ray tracer written in C, developed as part of the 42 curriculum. It renders
scenes described in plain-text `.rt` files and displays them in an interactive
window where the camera can be moved in real time and object materials edited on
the fly. Everything done with the Minilibx provided by 42, allowing only to put a pixel at a fixed location and push images to window.

The rendering core follows the techniques presented in *The Ray Tracer Challenge*
by Jamis Buck (tuples, transformation matrices, view transform, intersection
precomputation, reflection/refraction with the Schlick approximation), extended
with global illumination, supersampling, texturing and an interactive editor.

## Gallery

<!-- Replace these placeholders with your own renders. -->

![](docs/box_room.png)

Without Super-Sampling
![](docs/box_room_without_ss.png)

With indirect lighting
![](docs/box_room_indirect_light.png)

Textures and normal maps
![](docs/texture_nmap.png)

Moving mode with reduced resolution for smooth movement
![](docs/move_mode_box_room.png)

Transparency and refraction
![](docs/refraction_transp.png)

## Features

### Rendering
- Primitives: sphere, plane, cylinder and cube.
- Phong shading: ambient, diffuse and specular.
- Hard shadows.
- Recursive reflections with configurable depth.
- Refraction and transparency (Snell's law, Fresnel via the Schlick approximation).
- Indirect diffuse lighting (global illumination through random hemisphere bounces).
- Anti-aliasing through progressive supersampling (frame accumulation).
- Bilateral denoising filter to clean up noisy indirect lighting.

### Materials and texturing
- Per-object reflectivity, transparency and refractive index.
- Procedural patterns: stripe, gradient, ring and checker, with UV transforms.
- PNG texture mapping: base color, normal maps and ambient-occlusion maps.

### Lighting
- Ambient light.
- Multiple colored point lights.
- Configurable background color.

### Interactive viewport
- Scenes are loaded from an in-window file input or passed as a command-line argument.
- Free-fly camera: mouse look plus keyboard movement.
- Click an object to select it and edit its color, reflectivity, transparency,
  refractive index and texture maps live through on-screen sliders.
- Runtime toggles for indirect lighting, supersampling, denoising and render mode.
- Resolution is temporarily reduced while the camera moves to keep navigation responsive.

## Scene file format (`.rt`)

A scene is a text file with one element per line. Fields are space-separated,
vectors and colors are comma-separated (`x,y,z` and `R,G,B` with channels in the
`0-255` range). Lines starting with `#` are comments.

### Mandatory elements

| Element | Syntax                                             | Description                                  |
|---------|----------------------------------------------------|----------------------------------------------|
| Ambient | `A <ratio> <R,G,B>`                                 | Ambient light ratio and color                |
| Camera  | `C <x,y,z> <nx,ny,nz> <fov>`                        | Position, orientation vector, FOV in degrees |
| Light   | `L <x,y,z> <brightness> <R,G,B>`                   | Point light position, brightness and color   |
| Sphere  | `sp <x,y,z> <diameter> <R,G,B>`                    | Center, diameter, color                      |
| Plane   | `pl <x,y,z> <nx,ny,nz> <R,G,B>`                    | Point, normal, color                         |
| Cylinder| `cy <x,y,z> <ax,ay,az> <diameter> <height> <R,G,B>`| Center, axis, diameter, height, color        |

### Bonus elements

In the bonus build the point light keyword becomes `lpt`, and additional
elements are available:

| Element    | Syntax                                                          | Description                    |
|------------|-----------------------------------------------------------------|--------------------------------|
| Point light| `lpt <x,y,z> <brightness> <R,G,B>`                              | Point light (bonus keyword)    |
| Background | `bl <R,G,B>`                                                    | Background / sky color         |
| Cube       | `cb <x,y,z> <ax,ay,az> <sx,sy,sz> <R,G,B>`                      | Center, axis, size, color      |

### Bonus material fields

Each object (`sp`, `pl`, `cy`, `cb`) can take optional trailing fields:

```
<reflective> <transparency> <refractive> [ <uv_x,uv_y,uv_z> <uv_scale> <pattern | maps> ]
```

- `reflective`, `transparency`, `refractive` are floats.
- A pattern is: `<uv translation> <uv scale> <type> <colorA> <colorB>`, where
  `type` is one of `stripe`, `gradient`, `ring`, `checker`.
- Texture maps replace the pattern with: `<uv translation> <uv scale>
  <base_color.png> <normal.png> <ambient_occlusion.png>`.

Example (textured cube, bonus build):

```
cb 0,-10,-10 0,0,1 30,0.1,30 255,0,0 0 0 1 0,0,0 1 maps/floor_base.png maps/floor_norm.png maps/floor_ao.png
```
