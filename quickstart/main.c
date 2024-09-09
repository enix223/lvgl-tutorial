#include <Windows.h>

#include "lvgl/demos/lv_demos.h"
#include "lvgl/lvgl.h"

int main() {
  lv_init();

  int32_t zoom_level = 100;
  bool allow_dpi_override = false;
  bool simulator_mode = false;
  lv_display_t *display =
      lv_windows_create_display(L"LVGL DEMO", 800, 480, zoom_level, allow_dpi_override, simulator_mode);
  if (!display) {
    return -1;
  }

  lv_lock();

  lv_indev_t *pointer_device = lv_windows_acquire_pointer_indev(display);
  if (!pointer_device) {
    return -1;
  }

  lv_indev_t *keypad_device = lv_windows_acquire_keypad_indev(display);
  if (!keypad_device) {
    return -1;
  }

  lv_indev_t *encoder_device = lv_windows_acquire_encoder_indev(display);
  if (!encoder_device) {
    return -1;
  }

  lv_demo_benchmark();

  lv_unlock();

  while (1) {
    uint32_t time_till_next = lv_timer_handler();
    lv_delay_ms(time_till_next);
  }

  return 0;
}
