project('SDL dungeon', 'c', version: '0.0.1')

sdl2_dep = dependency('sdl2')
sdl2_image_dep = dependency('sdl2_image')

incdir = include_directories('include')

src=['src/main.c', 'src/game.c', 'src/dict.c', 'src/game_unix.c', 'src/game_win.c', 'src/texmgr.c']

executable('dungeon-sdl', src,
  dependencies : [sdl2_image_dep, sdl2_dep],
  include_directories : incdir,)
