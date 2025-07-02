# Makefile for iFly CLI Tool
# Requires Visual Studio Build Tools or Visual Studio to be installed

# Variables
CXX = cl
CXXFLAGS = /std:c++17 /EHsc /W3 /DWIN32_LEAN_AND_MEAN /DNOMINMAX
INCLUDES = /I"." /I"../737MAX_SDK" /I"../737MAX_SDK/sdk"
LIBS = user32.lib kernel32.lib
TARGET = ifly_cli.exe
SOURCES = main.cpp

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) /Fe$(TARGET) /link $(LIBS)

# Clean target
clean:
	del /Q *.obj *.exe *.pdb 2>nul || exit 0

# Install target (copy to parent directory)
install: $(TARGET)
	copy $(TARGET) ..

# Build and install
build-install: all install

.PHONY: all clean install build-install
