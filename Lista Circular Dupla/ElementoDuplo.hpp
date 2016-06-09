/* Copyright 2016 - Nathan Sargon Werlich */
#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template<typename T>
class ElementoDuplo {
 private:
	T *info;
	ElementoDuplo<T>* _next;
	ElementoDuplo<T>* _anterior;

 public:
	ElementoDuplo(const T& info, ElementoDuplo<T>* next,
	ElementoDuplo<T>* anterior) : info
	(new T(info)), _next(next), _anterior(anterior) {}

	~ElementoDuplo() {
		delete info;
	}

	ElementoDuplo<T>* getProximo() const {
		return _next;
	}
	ElementoDuplo<T>* getAnterior() const {
	    return _anterior;
	}

	T getInfo() const {
		return *info;
	}

	void setProximo(ElementoDuplo<T>* next) {
		_next = next;
	}
	void setAnterior(ElementoDuplo<T>* anterior) {
	    _anterior = anterior;
	}
};

#endif
