all:
	g++ image.cpp sphere.cpp drawable.cpp pixel3d.cpp point3d.cpp vector3d.cpp color.cpp objsys.cpp objsysarr.cpp event.cpp utilities.cpp displaywindow.cpp main.cpp -o raycaster -lsfml-system -lsfml-window -lsfml-graphics 
	./raycaster
