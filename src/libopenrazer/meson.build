# The name automatically gets "lib" prepended to "openrazer" -> "libopenrazer.so"
libopenrazer_sources = ['libopenrazer.cpp', 'razercapability.cpp']
libopenrazer = shared_library('openrazer',
                          libopenrazer_sources,
                          version : libopenrazer_version,
                          soversion : libopenrazer_version.split('.')[0],
                          dependencies : qt5_dep,
                          install : true)

# Demo executable
if get_option('buildtype') == 'debug'
  message('Building libopenrazerdemo...')
  libopenrazerdemo = executable('libopenrazerdemo', 'libopenrazerdemo.cpp',
                            dependencies : qt5_dep,
                            link_with : libopenrazer)
endif
