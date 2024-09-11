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

 public:
  void Draw();
  void SetBackgroundColor(lv_color_t &&color);
  void SetBackgroundColor(lv_color_t &color);
  Widget(int width, int heigt, int pos_x, int pos_y, lv_obj_t *screen);
};

void Widget::Draw() {
  lv_obj_set_size(this->widget, this->width, this->height);
  lv_obj_set_pos(this->widget, this->pos_x, this->pos_y);
}

void Widget::SetBackgroundColor(lv_color_t &&color) { this->SetBackgroundColor(color); }

void Widget::SetBackgroundColor(lv_color_t &color) {
  lv_style_t style;
  lv_style_init(&style);
  lv_style_set_bg_color(&style, color);
  lv_obj_add_style(this->widget, &style, LV_PART_MAIN);
}

Widget::Widget(int width, int heigt, int pos_x, int pos_y, lv_obj_t *screen) {
  this->widget = lv_obj_create(screen);
  this->width = width;
  this->height = height;
  this->pos_x = pos_x;
  this->pos_y = pos_y;
}

void drawScreen() {
  Widget widget = Widget(100, 100, 10, 10, lv_screen_active());
  widget.SetBackgroundColor(lv_color_hex(0xff0000));
  widget.Draw();
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

  drawScreen();

  lv_unlock();

  while (1) {
    uint32_t time_till_next = lv_timer_handler();
    lv_delay_ms(time_till_next);
  }

  return 0;
}
