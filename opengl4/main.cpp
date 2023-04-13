#include <windows.h>
#include <GL/freeglut.h>
#include "helpers/printer.h"
#include "animations/animations.h"

entity createEnemy(float x, float y) {
	std::vector<singleDrawable> d = drawableCreator::createEnemyDrawable();
	return entity(d,x,y);
}
entity createPlayer() {
	return entity(drawableCreator::createPlayerDrawable(), 0.0f, 0.0f);
}

field f = field(createPlayer());
testDraw td = testDraw(0.1f,point(0.0f, 0.0f), point(1.0f, 1.0f), color(1.0f, 0.0f, 0.0f));
void addEnemies() {
	const float angleStep = 3.1415f * 2.0f / 5.0f;
	for (int i = 0; i < 5; i++) {
		float x = cos(angleStep * i)/2.0f;
		float y = sin(angleStep * i)/2.0f;
		entity enemy = createEnemy(x, y);
		f.addEnemy(enemy);
	}
}
void setup() {
	addEnemies();
	printer::print(f);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
int tickTime = 5;
void draw(int val) {
	glClear(GL_COLOR_BUFFER_BIT);
	f.update();
	glFlush(); 
	glutPostRedisplay();
	//std::cout << val;
	glutTimerFunc(tickTime, draw, tickTime);
}
const int windowWidth = 1000;
const int windowHeight = 1000;
const int halfWidth = windowWidth / 2;
const int halfHeight = windowHeight / 2;
void mouseFunction(int button, int state, int x, int y) {
	std::cout << "Got mouse: " << x << " ; " << y << '\n';
	int offsetX = x - halfWidth;
	int offsetY = windowHeight - y - halfHeight;
	float mx = float(offsetX) / halfHeight;
	float my = float(offsetY) / halfHeight;
	std::cout << "Resized mouse: " << mx << " ; " << my << '\n';
	point moveTo = point(mx, my);
	f.setPlayerTarget(moveTo);
}
int frame = 0;
void drawFrame(int val) {
	glClear(GL_COLOR_BUFFER_BIT);
	td.drawFrame(val);
	frame++;
	if (frame == testDraw::MAX_FRAME) frame = 0;
	glFlush();
	glutPostRedisplay();
	glutTimerFunc(1, drawFrame, frame);
	
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Window");
	glutMouseFunc(mouseFunction);
	setup();
	glutTimerFunc(1, draw, 1);
	glutMainLoop();
	return 0;
};