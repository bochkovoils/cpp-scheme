//
// Created by work on 26.09.2024.
//

#ifndef CPP_SCHEME_OBSERVER_H
#define CPP_SCHEME_OBSERVER_H

#include <set>
#include <algorithm>

template<class T>
class Observer {
public:
    virtual void handle(T)=0;
    virtual ~Observer()=default;
};

template<class T>
class Observable {
private:
    std::set<Observer<T>*> _observers;
public:
    virtual void emit(T);

    void subscribe(Observer<T>*);
    void unsubscribe(Observer<T>*);

    virtual ~Observable()=default;
};

template<class T>
void Observable<T>::subscribe(Observer<T> *o) {
    _observers.insert(o);
}

template<class T>
void Observable<T>::unsubscribe(Observer<T> *o) {
    _observers.erase(o);
}

template<class T>
void Observable<T>::emit(T t) {
    std::for_each(_observers.begin(), _observers.end(), [&t](auto s) {
        s->handle(t);
    });
}


#endif //CPP_SCHEME_OBSERVER_H
