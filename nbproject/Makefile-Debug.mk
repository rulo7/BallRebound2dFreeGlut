#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Circulo.o \
	${OBJECTDIR}/src/Lapiz.o \
	${OBJECTDIR}/src/Obstaculo.o \
	${OBJECTDIR}/src/Pelota.o \
	${OBJECTDIR}/src/Triangulo.o \
	${OBJECTDIR}/src/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pelota_ulti

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pelota_ulti: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pelota_ulti ${OBJECTFILES} ${LDLIBSOPTIONS} -lglut -lGL -lGLU

${OBJECTDIR}/src/Circulo.o: src/Circulo.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/GL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Circulo.o src/Circulo.cpp

${OBJECTDIR}/src/Lapiz.o: src/Lapiz.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/GL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Lapiz.o src/Lapiz.cpp

${OBJECTDIR}/src/Obstaculo.o: src/Obstaculo.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/GL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Obstaculo.o src/Obstaculo.cpp

${OBJECTDIR}/src/Pelota.o: src/Pelota.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/GL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Pelota.o src/Pelota.cpp

${OBJECTDIR}/src/Triangulo.o: src/Triangulo.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/GL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Triangulo.o src/Triangulo.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/GL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pelota_ulti

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
