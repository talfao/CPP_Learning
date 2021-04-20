#include <cstdio>

struct Element {
    Element *next{nullptr};
    Element *before{nullptr};
    void insert_after(Element *new_element) {

        new_element->before = this;
        new_element->next = this->next;
        if ((this->next) !=
            NULL) { // Without the condition, it will throw segmentation fault.
            this->next->before = new_element;
        }
        this->next = new_element;
    }
    void insert_before(Element *new_element) {
        new_element->before = this->before;
        new_element->next = this;
        if (this->before != NULL) {
            this->before->next = new_element;
        }
        this->before = new_element;
    }

    char prefix[2];
    int operating_number;
};

int main() {

    Element tropper1, tropper2, tropper3, tropper4, tropper5; // creating
                                                              // objects
    tropper1.prefix[0] = 'P';
    tropper1.prefix[1] = 'B';
    tropper1.operating_number = 121;

    tropper1.insert_after(&tropper2); // Insert tropper2 after tropper1

    tropper2.prefix[0] = 'E';
    tropper2.prefix[1] = 'P';
    tropper2.operating_number = 3211;

    tropper2.insert_after(&tropper3); // Insert tropper3 after tropper2

    tropper3.prefix[0] = 'L';
    tropper3.prefix[1] = 'S';
    tropper3.operating_number = 4356;

    tropper4.prefix[0] = 'A';
    tropper4.prefix[1] = 'B';
    tropper4.operating_number = 4444;

    tropper5.prefix[0] = 'C';
    tropper5.prefix[1] = 'D';
    tropper5.operating_number = 4234;

    tropper2.insert_before(&tropper4); // Insert tropper4 before tropper2
    tropper1.insert_after(&tropper5);  // Insert tropper5 after tropper1

    for (Element *cursor = &tropper1; cursor; cursor = cursor->next) {
        printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1],
               cursor->operating_number);
    } // printing in -> way

    printf("----------------\n");

    for (Element *cursor = &tropper3; cursor; cursor = cursor->before) {
        printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1],
               cursor->operating_number);
    } // printing in <- way
}
