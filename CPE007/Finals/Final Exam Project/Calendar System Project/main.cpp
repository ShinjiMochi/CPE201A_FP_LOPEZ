#include "calendar.hpp"
#include "menuGUI.hpp"
#include "credentials.hpp"

// ------- Important Arrays ------- //

Credentials studentCreds[credSize];
Credentials teachCreds[credSize];
schedInfo mainCalendar[12][6][7];

// ------- Task CRUD ------- //

int main() {
	createCalendar(mainCalendar);
	opening();
    return 0;
}
