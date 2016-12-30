//
// Created by Elias on 01.11.16.
//

#ifndef EX1_DUMB_POINTER_H
#define EX1_DUMB_POINTER_H


template <typename F>
class dumb_pointer {
    F *internal_obj;
private:
    void init(F *ob) {
        internal_obj = ob;
    }
    void clear() {
        delete internal_obj;
    }
public:
    dumb_pointer(F *ob) { init(ob); }
    dumb_pointer(const dumb_pointer &d) { init(d.get()); }
    ~dumb_pointer() { clear(); }

    F * get() const {
        return internal_obj;
    }

    F operator*() const {
        return *internal_obj;
    }

    F *operator->() const {
        return internal_obj;
    }
};




#endif //EX1_DUMB_POINTER_H
