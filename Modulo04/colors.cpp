#include "colors.h"

const char* getColorCode(Color color) {
    switch (color) {
        case RED_COLOR: return RED;
        case GREEN_COLOR: return GREEN;
        case YELLOW_COLOR: return YELLOW;
        case BLUE_COLOR: return BLUE;
        case MAGENTA_COLOR: return MAGENTA;
        case RESET_COLOR: return RESET;
        default: return RESET;
    }
}
