add_subdirectory(libs)

if (NOT LIBRARY_ONLY)
    add_executable(lab1_task1 lab1/task1/main.cpp)
    add_executable(lab1_task2 lab1/task2/main.cpp)
    add_executable(lab2 lab2/main.cpp)
    add_executable(lab4 lab4/main.cpp)
    add_executable(lab5 lab5/main.cpp)
    add_executable(lab6_task1 lab6/task1/main.cpp)
    add_executable(lab6_task2 lab6/task2/main.cpp)
    add_executable(lab7 lab7/main.cpp)
    add_executable(lab8_task1 lab8/task1/main.cpp)
    add_executable(lab8_task2 lab8/task2/main.cpp)
    add_executable(lab9 lab9/main.cpp)

    if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
        qt_add_executable(lab1_task3
            MANUAL_FINALIZATION
            lab1/task3/main.cpp
            lab1/task3/mainwindow.cpp
            lab1/task3/mainwindow.h
            lab1/task3/mainwindow.ui
            lab1/task3/resources.qrc
        )

        qt_add_executable(lab1_task4
            MANUAL_FINALIZATION
            lab1/task4/main.cpp
            lab1/task4/mainwindow.cpp
            lab1/task4/mainwindow.h
            lab1/task4/mainwindow.ui
        )
    else()
        if(ANDROID)
            add_library(lab1_task3 SHARED
                ${PROJECT_SOURCES}
            )
            add_library(lab1_task4 SHARED
                ${PROJECT_SOURCES}
            )
    # Define properties for Android with Qt 5 after find_package() calls as:
    #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
        else()
            add_executable(lab1_task3
                ${PROJECT_SOURCES}
            )

            add_executable(lab1_task4
                ${PROJECT_SOURCES}
            )
        endif()
    endif()

    target_link_libraries(lab1_task3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
    target_link_libraries(lab1_task4 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

    if(${QT_VERSION} VERSION_LESS 6.1.0)
      set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.lab1_task3)
      set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.lab1_task4)
    endif()

    set_target_properties(lab1_task3 PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )

    set_target_properties(lab1_task4 PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )

    include(GNUInstallDirs)
    install(TARGETS lab1_task3
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
    install(TARGETS lab1_task4
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

    if(QT_VERSION_MAJOR EQUAL 6)
        qt_finalize_executable(lab1_task3)
        qt_finalize_executable(lab1_task4)
    endif()


    target_link_libraries(lab2 alg)
    target_link_libraries(lab4 alg)
    target_link_libraries(lab5 alg)
    target_link_libraries(lab7 alg)
endif()
