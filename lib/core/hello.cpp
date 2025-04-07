#include <print>

#include "hello.h"

void hello(std::string_view message) {
    std::println("{}", message);
}
