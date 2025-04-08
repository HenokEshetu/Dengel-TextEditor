#include "window.h"

int main()
{
    auto winInfo = dengel_ui::WindowInfo{ "Hello there", 800, 600 };
    auto window = dengel_ui::Window{ winInfo };
    window.Show();
}
