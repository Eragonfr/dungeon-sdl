# Dungeon sdl

This project is a basic C [SDL2][SDL] project that uses [CMake][] as a build system.


## Dependencies

- [Git][]
- C Compiler (gcc, ...)
- [CMake][]
- [SDL2][SDL] library
- [SDL2_image][] library

**Optional packages:**

- [SDL2_ttf][] library
- [SDL2_net][] library
- [SDL2_mixer][] library
- [SDL2_gfx][] library

## Build instructions

```sh
# Clone this repo
git clone https://github.com/Eragonfr/dungeon-sdl
cd dungeon-sdl
git submodule update --init --recursive

# Create a build folder
mkdir build
cd build

# Build
cmake ..
make

# Run
./dungeon-sdl
```

## License

Unknown License for now.

[Build system](https://gitlab.com/aminosbh/basic-c-sdl-project)

[SDL]: https://www.libsdl.org
[CMake]: https://cmake.org
[Git]: https://git-scm.com
[SDL2_image]: https://www.libsdl.org/projects/SDL_image
[SDL2_ttf]: https://www.libsdl.org/projects/SDL_ttf
[SDL2_net]: https://www.libsdl.org/projects/SDL_net
[SDL2_mixer]: https://www.libsdl.org/projects/SDL_mixer
[SDL2_gfx]: http://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx
