//
// Created by Elias on 01.11.16.
//

#ifndef EX1_SMART_POINTER_H
#define EX1_SMART_POINTER_H

template <typename F>
class smart_pointer {
    F *internal_obj;
    int *num_refs;
private:
    void init(F *ob) {
        internal_obj = ob;
        num_refs = new int(1);
    }
    void decrease_refs() {
        if(--(*num_refs) == 0) {
            delete internal_obj;
            delete num_refs;
        }
    }
    void copy_smart_pointer(const smart_pointer &d) {
        num_refs = d.num_refs;
        (*num_refs)++;
        internal_obj = d.internal_obj;
    }
public:
    smart_pointer(F *ob) { init(ob); }
    smart_pointer(const smart_pointer &d) { copy_smart_pointer(d); }
    ~smart_pointer() { decrease_refs(); }

    F * get() const {
        return internal_obj;
    }

    int counter() const {
        return *num_refs;
    }

    F operator*() const {
        return *internal_obj;
    }

    F *operator->() const {
        return internal_obj;
    }

    smart_pointer &operator=(smart_pointer &sp) {
        if(internal_obj == sp.internal_obj) return *this;

        decrease_refs();
        copy_smart_pointer(sp);

        return *this;
    }
};


#endif //EX1_SMART_POINTER_H
