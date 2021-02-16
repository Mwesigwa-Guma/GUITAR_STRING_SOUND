#include <stdint.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CircularBuffer.h"

using namespace std;

class StringSound{

	public:
		StringSound();

		StringSound(double frequency );

		~StringSound();

		StringSound(vector<sf::Int16> init);

		void pluck();

		void tic();

		sf::Int16 sample();

		int time();

	private:
		CircularBuffer* cirB;
		int cap;
		int tic_counter;

};


