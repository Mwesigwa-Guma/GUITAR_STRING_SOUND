
#include "StringSound.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define DECAY_F 0.996


using namespace std ;

StringSound::StringSound() = default;

//  String constrctor takes frequency as argument
StringSound::StringSound(double frequency){
	int capacity = static_cast<int>(ceil((44100.0/frequency)));
	cirB = new CircularBuffer(capacity);
	cap = capacity;
	this->tic_counter = 0;

	for(int i = 0; i < capacity; i++)
		this->cirB->enqueue(0);
}

//  StringSound constructor takes sample as argument
StringSound::StringSound(vector<sf::Int16> init){

	int capacity = init.size();
	this->cirB = new CircularBuffer(capacity);
	this->cap = capacity;

	for(int i =0; i < capacity; i++){
		this->cirB->enqueue(init.at(i));
	}

	this->tic_counter = 0;	

}

//  pluck function creates white noise that replaces current values in CircularBuffer
void StringSound::pluck(){
	int16_t random_num;
	int capacity = this->cirB->get_capacity();
	
	this->cirB->empty();

        //  ensures randomness of int16_t numbers 
	srand(::time(NULL));

	for(int i = 0; i < capacity; i++){
		random_num = -32768 + (rand() % ((32768+1)-(-32768 ))); 
		this->cirB->enqueue(random_num);
	}
	

}

//  Advances simultion one step   
void StringSound::tic(){
	double new_value;
	double first, second;

	first = this->cirB->peek();

	this->cirB->dequeue();

	second = this->cirB->peek();

	new_value = DECAY_F * ((first + second)/2);
	this->cirB->enqueue(new_value);

	this->tic_counter++;
}

//  returns the current sample 
sf::Int16 StringSound::sample(){
	return this->cirB->peek();
}

//  returns number of has tic was called 
int StringSound::time(){
	return this->tic_counter;
}

//  Destructor destroys dynamic memory created in constructor 
StringSound::~StringSound(){
	delete cirB;
}
