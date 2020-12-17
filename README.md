# Dungeon sdl

This project is a basic C [SDL2][SDL] project that uses [Meson](https://mesonbuild.com/) as a build system.


## Dependencies

- C Compiler (gcc, ...)
- [Meson][https://mesonbuild.com/]
- [SDL]: https://www.libsdl.org
- [Git]: https://git-scm.com
- [SDL2_image]: https://www.libsdl.org/projects/SDL_image

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

# Build
meson build
ninja -C build

# Run
build/dungeon-sdl
```

## License

Unknown License for now.
