#pragma once
#include "Libraries.h"
class RuntimeException {
private:
	string message;
public:
	RuntimeException(const string& message) {
		this->message = message;
	}
	string ErrorMessage() const { return this->message; }
};

class InvalidOption : public RuntimeException {
public:
	InvalidOption(const string& error) : RuntimeException(error) {}
};

class EmptyTree : public RuntimeException {
public:
	EmptyTree(const string& error) : RuntimeException(error) {}
};

class DataNotFound : public RuntimeException{
public:
	DataNotFound(const string& error) : RuntimeException(error) {}
};

class ExistingData : public RuntimeException {
public:
	ExistingData(const string& error) : RuntimeException(error) {}
};
class InvalidOperation : public RuntimeException {
public:
	InvalidOperation(const string& error) : RuntimeException(error) {}
};
class InvalidInput : public RuntimeException {
public:
	InvalidInput(const string& error) : RuntimeException(error) {}
};