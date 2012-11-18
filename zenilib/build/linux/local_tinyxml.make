# GNU Make project makefile autogenerated by Premake
ifndef config
  config=debug32
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifndef RESCOMP
  ifdef WINDRES
    RESCOMP = $(WINDRES)
  else
    RESCOMP = windres
  endif
endif

ifeq ($(config),debug32)
  OBJDIR     = obj/x32/Debug/local_tinyxml
  TARGETDIR  = ../../lib/d32
  TARGET     = $(TARGETDIR)/liblocal_tinyxml_d.so
  DEFINES   += -D_LINUX -D_DEBUG -DDEBUG -DTEST_NASTY_CONDITIONS -DDISABLE_CPP11 -DGLEW_NO_GLU -DDISABLE_CG -DOGG_DLL= -DVORBIS_DLL= -DVORBISFILE_DLL= -DDISABLE_DX9 -DDISABLE_WGL -DTINYXML_DLL= -DTINYXML_EXT= -DZENI_DLL= -DZENI_EXT= -DZENI_AUDIO_DLL= -DZENI_AUDIO_EXT= -DZENI_CORE_DLL= -DZENI_CORE_EXT= -DZENI_GRAPHICS_DLL= -DZENI_GRAPHICS_EXT= -DZENI_NET_DLL= -DZENI_NET_EXT= -DZENI_REST_DLL= -DZENI_REST_EXT=
  INCLUDES  += -I../../jni/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m32 -fPIC -w
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -L../../lib/d32 -shared -m32 -L/usr/lib32 -Wl,-rpath,'$$ORIGIN' -Wl,--hash-style=both
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release32)
  OBJDIR     = obj/x32/Release/local_tinyxml
  TARGETDIR  = ../../lib/x32
  TARGET     = $(TARGETDIR)/liblocal_tinyxml.so
  DEFINES   += -D_LINUX -DNDEBUG -DDISABLE_CPP11 -DGLEW_NO_GLU -DDISABLE_CG -DOGG_DLL= -DVORBIS_DLL= -DVORBISFILE_DLL= -DDISABLE_DX9 -DDISABLE_WGL -DTINYXML_DLL= -DTINYXML_EXT= -DZENI_DLL= -DZENI_EXT= -DZENI_AUDIO_DLL= -DZENI_AUDIO_EXT= -DZENI_CORE_DLL= -DZENI_CORE_EXT= -DZENI_GRAPHICS_DLL= -DZENI_GRAPHICS_EXT= -DZENI_NET_DLL= -DZENI_NET_EXT= -DZENI_REST_DLL= -DZENI_REST_EXT=
  INCLUDES  += -I../../jni/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -m32 -fPIC -w
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -L../../lib/x32 -s -shared -m32 -L/usr/lib32 -Wl,-rpath,'$$ORIGIN' -Wl,--hash-style=both
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug64)
  OBJDIR     = obj/x64/Debug/local_tinyxml
  TARGETDIR  = ../../lib/d64
  TARGET     = $(TARGETDIR)/liblocal_tinyxml_d.so
  DEFINES   += -D_LINUX -D_DEBUG -DDEBUG -DTEST_NASTY_CONDITIONS -DX64 -DDISABLE_CPP11 -DGLEW_NO_GLU -DDISABLE_CG -DOGG_DLL= -DVORBIS_DLL= -DVORBISFILE_DLL= -DDISABLE_DX9 -DDISABLE_WGL -DTINYXML_DLL= -DTINYXML_EXT= -DZENI_DLL= -DZENI_EXT= -DZENI_AUDIO_DLL= -DZENI_AUDIO_EXT= -DZENI_CORE_DLL= -DZENI_CORE_EXT= -DZENI_GRAPHICS_DLL= -DZENI_GRAPHICS_EXT= -DZENI_NET_DLL= -DZENI_NET_EXT= -DZENI_REST_DLL= -DZENI_REST_EXT=
  INCLUDES  += -I../../jni/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m64 -fPIC -w
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -L../../lib/d64 -shared -m64 -L/usr/lib64 -Wl,-rpath,'$$ORIGIN' -Wl,--hash-style=both
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release64)
  OBJDIR     = obj/x64/Release/local_tinyxml
  TARGETDIR  = ../../lib/x64
  TARGET     = $(TARGETDIR)/liblocal_tinyxml.so
  DEFINES   += -D_LINUX -DNDEBUG -DX64 -DDISABLE_CPP11 -DGLEW_NO_GLU -DDISABLE_CG -DOGG_DLL= -DVORBIS_DLL= -DVORBISFILE_DLL= -DDISABLE_DX9 -DDISABLE_WGL -DTINYXML_DLL= -DTINYXML_EXT= -DZENI_DLL= -DZENI_EXT= -DZENI_AUDIO_DLL= -DZENI_AUDIO_EXT= -DZENI_CORE_DLL= -DZENI_CORE_EXT= -DZENI_GRAPHICS_DLL= -DZENI_GRAPHICS_EXT= -DZENI_NET_DLL= -DZENI_NET_EXT= -DZENI_REST_DLL= -DZENI_REST_EXT=
  INCLUDES  += -I../../jni/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -m64 -fPIC -w
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -L../../lib/x64 -s -shared -m64 -L/usr/lib64 -Wl,-rpath,'$$ORIGIN' -Wl,--hash-style=both
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/tinyxmlparser.o \
	$(OBJDIR)/tinyxml.o \
	$(OBJDIR)/tinyxmlerror.o \
	$(OBJDIR)/tinystr.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking local_tinyxml
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning local_tinyxml
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
ifeq (posix,$(SHELLTYPE))
	-$(SILENT) cp $< $(OBJDIR)
else
	$(SILENT) xcopy /D /Y /Q "$(subst /,\,$<)" "$(subst /,\,$(OBJDIR))" 1>nul
endif
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
endif

$(OBJDIR)/tinyxmlparser.o: ../../jni/external/tinyxml/tinyxmlparser.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/tinyxml.o: ../../jni/external/tinyxml/tinyxml.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/tinyxmlerror.o: ../../jni/external/tinyxml/tinyxmlerror.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/tinystr.o: ../../jni/external/tinyxml/tinystr.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"

-include $(OBJECTS:%.o=%.d)
