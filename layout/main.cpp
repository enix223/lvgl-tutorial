#include <Windows.h>
#include <stdlib.h>

#include "lvgl/lvgl.h"

class Widget {
 private:
  int width;
  int height;
  int pos_x;
  int pos_y;
  lv_obj_t *widget;
  lv_style_t style;

 public:
  void SetBackgroundColor(uint32_t colorHex);
  Widget(int width, int heigt, int pos_x, int pos_y, lv_obj_t *screen);
};

void Widget::SetBackgroundColor(uint32_t colorHex) {
  lv_style_init(&style);
  lv_style_set_bg_color(&style, lv_color_hex(colorHex));
  lv_style_set_bg_opa(&style, LV_OPA_COVER);
  lv_obj_add_style(widget, &style, LV_PART_MAIN);
}

Widget::Widget(int w, int h, int x, int y, lv_obj_t *screen) {
  widget = lv_obj_create(screen);
  width = w;
  height = h;
  pos_x = x;
  pos_y = y;
  lv_obj_set_size(widget, width, height);
  lv_obj_set_pos(widget, pos_x, pos_y);
}

void draw_screen() {
  static Widget widget(100, 100, 0, 0, lv_screen_active());
  widget.SetBackgroundColor(0xFF0000);
}

int main() {
  lv_init();

  int zoom_level = 100;
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

  draw_screen();

  lv_unlock();

  while (1) {
    uint32_t time_till_next = lv_timer_handler();
    lv_delay_ms(time_till_next);
  }

  return 0;
}
