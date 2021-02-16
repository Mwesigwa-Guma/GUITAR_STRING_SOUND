/*
  Copyright Mwesigwa Thomas Guma, 2020
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "CircularBuffer.h"
#include "StringSound.h"

#define CONCERT_A 440.0
#define SAMPLES_PER_SEC 44100

//  generates and returns a sample
vector<int16_t> makeSamples(StringSound& gs) {
	std::vector < int16_t > samples;

  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}

void create_buffers(vector<vector<int16_t>>& samples, vector<sf::SoundBuffer>& buffers);

void create_sounds(vector<sf::Sound>& sounds, vector<sf::SoundBuffer>& buffers);

double calculate_freq(int i);

using namespace std;

int main(int argc, char* argv[]) {
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound Lite");
  sf::Event event;
  double freq;

  vector<vector <int16_t>> samples;
  vector<int16_t> samp;
  vector<sf::SoundBuffer> buffers;
  vector<sf::Sound> sounds;
 
  for(int i = 1; i <= 37; i++){
	freq = calculate_freq(i);
  	StringSound gs = StringSound(freq);
	samp = makeSamples(gs);
	samples.push_back(samp);
  }

  create_buffers(samples, buffers);

  create_sounds(sounds, buffers);

  //  while window is open, if a key is pressed that corresponds to any keys below then a sound is produced 
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Q:
          sounds.at(0).play();
          break;

        case sf::Keyboard::Num2:
          sounds.at(1).play();
          break;

	case sf::Keyboard::W:
	  sounds.at(2).play();
	  break;
	  
	case sf::Keyboard::E:
          sounds.at(3).play();
          break;

	case sf::Keyboard::Num4:
          sounds.at(4).play();
          break;

	case sf::Keyboard::R:
          sounds.at(5).play();
          break;

	case sf::Keyboard::Num5:
          sounds.at(6).play();
          break;

	case sf::Keyboard::T:
          sounds.at(7).play();
          break;

	case sf::Keyboard::Y:
          sounds.at(8).play();
          break;

	case sf::Keyboard::Num7:
          sounds.at(9).play();
          break;

	case sf::Keyboard::U:
          sounds.at(10).play();
          break;

	case sf::Keyboard::Num8:
          sounds.at(11).play();
          break;

	 case sf::Keyboard::I:
          sounds.at(12).play();
          break;

	case sf::Keyboard::Num9:
          sounds.at(13).play();
          break;

	case sf::Keyboard::O:
          sounds.at(14).play();
          break;


	case sf::Keyboard::P:
          sounds.at(15).play();
          break;

	case sf::Keyboard::Hyphen:
          sounds.at(16).play();
          break;

	case sf::Keyboard::LBracket:
          sounds.at(17).play();
          break;

	case sf::Keyboard::Equal:
          sounds.at(18).play();
          break;

	case sf::Keyboard::Z:
          sounds.at(19).play();
          break;

	case sf::Keyboard::X:
          sounds.at(20).play();
          break;

	case sf::Keyboard::D:
          sounds.at(21).play();
          break;

	case sf::Keyboard::C:
          sounds.at(22).play();
          break;

	case sf::Keyboard::F:
          sounds.at(23).play();
          break;

	case sf::Keyboard::V:
          sounds.at(24).play();
          break;

	case sf::Keyboard::G:
          sounds.at(25).play();
          break;

	case sf::Keyboard::B:
         sounds.at(26).play();
          break;

	case sf::Keyboard::N:
          sounds.at(27).play();
          break;

	case sf::Keyboard::J:
          sounds.at(28).play();
          break;

	case sf::Keyboard::M:
          sounds.at(29).play();
          break;

	case sf::Keyboard::K:
          sounds.at(30).play();
          break;

	case sf::Keyboard::Comma:
          sounds.at(31).play();
          break;

	case sf::Keyboard::Period:
          sounds.at(32).play();
          break;

	case sf::Keyboard::Semicolon:
          sounds.at(33).play();
          break;

	case sf::Keyboard::BackSlash:
          sounds.at(34).play();
          break;

	case sf::Keyboard::Quote:
          sounds.at(35).play();
          break;

	case sf::Keyboard::Space:
          sounds.at(36).play();
          break;

        default:
          break;
        }

      default:
        break;
      }

      window.clear();
      window.display();
    }
  }
  return 0;
}

//  creates sfml SoundBuffers 
void create_buffers(vector<vector<int16_t>>& samples, vector<sf::SoundBuffer>& buffers ){

	for(size_t i = 0; i < samples.size(); i++){
		sf::SoundBuffer buff;
		if(!buff.loadFromSamples(&(samples.at(i))[0], samples.at(i).size(), 2, 44100))
			throw runtime_error("sf::SoundBuffer coundn't load");

		buffers.push_back(buff);
	}

}

//  creates sfml Sounds
void create_sounds(vector<sf::Sound>& sounds, vector<sf::SoundBuffer>& buffers){
	for(size_t i = 0; i < buffers.size(); i++){
		sf::Sound sound;
		sound.setBuffer(buffers.at(i));
		sounds.push_back(sound);
	}
}

//  calculates and returns current frequency 
double calculate_freq(int i){
	return CONCERT_A * pow(2, (i-24)/12.0);

}
