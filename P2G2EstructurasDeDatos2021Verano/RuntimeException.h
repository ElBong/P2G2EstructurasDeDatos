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

class WrongData : public RuntimeException{
public:
	WrongData(const string& error) : RuntimeException(error) {}
};

class DuplicatedData : public RuntimeException {
public:
	DuplicatedData(const string& error) : RuntimeException(error) {}
};
class InvalidOperation : public RuntimeException {
public:
	InvalidOperation(const string& error) : RuntimeException(error) {}
};