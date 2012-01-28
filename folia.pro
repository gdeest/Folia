QT += sql
TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += FoliaException.h FoliaMainWindow.h FoliaModel.h NewClassDialog.h NewSampleDialog.h FeatureExtractor.h FractalDimension.h Couleurs.h Shape.h Step.h Corners.h DefaultExtractor.h
SOURCES += FoliaMainWindow.cpp FoliaException.cpp FoliaModel.cpp NewClassDialog.cpp NewSampleDialog.cpp FeatureExtractor.cpp FractalDimension.cpp DefaultExtractor.cpp Shape.cpp Couleurs.cpp Step.cpp Corners.cpp main.cpp

FORMS = folia.ui newclass.ui newsample.ui

INCLUDES += /opt/local/include
INCLUDES += /opt/local/include/ImageMagick
unix:LIBS += -L/opt/local/lib -lMagick++ -lm
