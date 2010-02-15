#include <assert.h>

#include "otDataStream.h"
#include "otModule.h"

otDataStream::otDataStream(std::string format) {
	this->format = format;
	this->data	 = NULL;
}

otDataStream::~otDataStream() {
}

std::string otDataStream::getFormat() {
	return this->format;
}

void otDataStream::lock() {
	// FIXME
}

void otDataStream::unlock() {
	// FIXME
}

void otDataStream::push(void *data) {
	this->lock();
	this->data = data;
	this->unlock();

	this->notifyObservers();
}

void otDataStream::addObserver(otModule *module) {
	this->observers.push_back(module);
}

void otDataStream::removeObserver(otModule *module) {
	assert("unimplemented" && 0);
}

void otDataStream::notifyObservers() {
	std::vector<otModule *>::iterator it;
	for (it = this->observers.begin(); it != this->observers.end(); it++ )
		(*it)->update(this);
}

void *otDataStream::getData() {
	return this->data;
}