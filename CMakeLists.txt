cmake_minimum_required(VERSION 3.26)
project(Porjet_C C)

set(CMAKE_C_STANDARD 23)


add_executable(Porjet_C main.c
        combat.h
        struct.h
        init.c
        init.h
        destroy.h
        destroy.c
        setGet.h
        setGet.c
        func.h
        func.c
        combat.c
        visual.h
        visual.c
        lifeCycle.h
        lifeCycle.c
        splashScreen.c
        splashScreen.h
        deathScreen.c
        deathScreen.h
        game.c
        game.h
        fileReader.c
        fileReader.h
        fileWriter.h
        fileWriter.c)
