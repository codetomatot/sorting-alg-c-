#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace sf;
int main() {
    srand(time(NULL));
    const int arrSize = 8;
    int arr[arrSize];
    for(int i = 0; i < arrSize; i++) {
        arr[i] = rand() % 180;
    }
    // int len = *(&arr + 1) - arr;

    RenderWindow window(VideoMode(200,200), "sfml works");
    RectangleShape rect;
    Clock sortTimer;

    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed) {
                window.close();
            }
        }   
        window.clear();

        int start = 0;
        for(int i = 0; i < arrSize; i++) {
            rect.setSize(Vector2f(10, -arr[i]));
            rect.setPosition(start+=20, 180);

            int cv = arr[i];
            int pos = i;
            
            if(sortTimer.getElapsedTime().asSeconds() > 0.5f) {
                while(pos > 0 && arr[pos-1] > cv) {
                    arr[pos] = arr[pos-1];
                    pos = pos - 1;
                    sortTimer.restart();
                }
                arr[pos] = cv;
            }
            // std::cout << arr[i] << std::endl;
            window.draw(rect);
        }

        window.display();
    }

    return 0;
}