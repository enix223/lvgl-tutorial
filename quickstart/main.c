#include <Windows.h>

#include "lvgl/demos/lv_demos.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/lvgl.h"

static void lv_example_label(void);

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

  lv_example_label();
  // lv_demo_widgets();

  lv_unlock();

  while (1) {
    uint32_t time_till_next = lv_timer_handler();
    lv_delay_ms(time_till_next);
  }

  return 0;
}

static void lv_example_label(void) {
  lv_obj_t *label1 = lv_label_create(lv_screen_active());
  lv_label_set_long_mode(label1, LV_LABEL_LONG_WRAP); /*Break the long lines*/
  lv_label_set_text(label1, "Hello world.");
  lv_obj_set_width(label1, 150); /*Set smaller width to make the lines wrap*/
  lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label1, LV_ALIGN_CENTER, 0, -40);

  lv_obj_t *label2 = lv_label_create(lv_screen_active());
  lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
  lv_obj_set_width(label2, 150);
  lv_label_set_text(label2, "It is a circularly scrolling text. ");
  lv_obj_align(label2, LV_ALIGN_CENTER, 0, 40);
}