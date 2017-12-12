TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    += $$(GVSDKDIR)/../dependencies/pepper_49/include \
    += $$(OSGDIR)/include
#osgdb
        LIBS += -L$$(OSGLIBDIR)/osgPlugins-3.4.0 \
                -losgdb_lua -losgdb_tf -losgdb_trk -losgdb_osc -losgdb_pvr -losgdb_zip -losgdb_freetype -losgdb_txp -losgdb_ply \
                -losgdb_lwo -losgdb_osgjs -losgdb_gles -losgdb_mdl -losgdb_bsp -losgdb_txf -losgdb_shp -losgdb_tgz -losgdb_osgtgz \
                -losgdb_md2 -losgdb_lwsd -losgdb_logo -losgdb_pov -losgdb_ac -losgdb_3ds -losgdb_stl -losgdb_pic -losgdb_obj \
                -losgdb_openflight -losgdb_dxf -losgdb_x -losgdb_bvh -losgdb_dw -losgdb_gz -losgdb_curl -losgdb_p3d -losgdb_3dc \
                -losgdb_ogr -losgdb_gdal \#-losgdb_tiff
                -losgdb_png -losgdb_jp2 -losgdb_jpeg -losgdb_ktx -losgdb_vtf -losgdb_dot \
                -losgdb_hdr -losgdb_osg -losgdb_tga -losgdb_dds -losgdb_pnm -losgdb_bmp -losgdb_rgb -losgdb_glsl -losgdb_cfg \
                -losgdb_ive -losgdb_osg -losgdb_osgterrain -losgdb_osgshadow -losgdb_osgviewer -losgdb_revisions -losgdb_normals \
                -losgdb_trans -losgdb_scale -losgdb_rot -losgdb_osga -losgdb_deprecated_osgwidget -losgdb_deprecated_osgvolume \
                -losgdb_deprecated_osgterrain -losgdb_deprecated_osgshadow -losgdb_deprecated_osgviewer -losgdb_deprecated_osgtext \
                -losgdb_deprecated_osgsim -losgdb_deprecated_osgfx -losgdb_deprecated_osganimation -losgdb_deprecated_osgparticle \
                -losgdb_deprecated_osg -losgdb_serializers_osgui -losgdb_serializers_osgviewer -losgdb_serializers_osgvolume \
                -losgdb_serializers_osgtext -losgdb_serializers_osgterrain -losgdb_serializers_osgga -losgdb_serializers_osgshadow \
                -losgdb_serializers_osgsim -losgdb_serializers_osgparticle -losgdb_serializers_osgmanipulator -losgdb_serializers_osgfx \
                -losgdb_serializers_osganimation -losgdb_serializers_osgutil -losgdb_serializers_osg

        LIBS += -L$$(OSGLIBDIR)    \
                -losgTerrain -losgSim -losgShadow \
                -losgPresentation -losgUI -losgWidget -losgVolume -losgParticle -losgManipulator \
                -losgFX -losgAnimation -losgViewer -losgText -losgGA -losgDB -losgUtil -losg -lOpenThreads


        LIBS += -L$$(GVSDKDIR)/../dependencies/lib/linux_x64 -lSparkCore -lSpark_GL -lsqlite3
        LIBS += -L$$(TRDPARTYDIR)/lib  -lgdal111 -lxtiff -lgeotiff -ljasper -lcurl -lfreetype   -lglut \
                                 -ljpeg -lleveldb_static -llua -lpng16 \
                                 -lproj -lsqlite    -lgeos_c -lgeos-static -lexpat \
                                 -ltiff  -lz
        LIBS += -L$$(GVSDKDIR)/../dependencies/lib/linux_x64 -lppapi_gles2 -lcef -lcef_dll_wrapper -lpthread
        LIBS +=  -ldl
SOURCES += main.cpp
