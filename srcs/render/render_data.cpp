#include "../../incs/render.hpp"
#include <iostream>

template <typename I> std::string n2hexstr(I w, size_t hex_len = sizeof(I)<<1);

bool	render_register(Info &info);
bool	render_user_data_segment(Info &info);

bool	render_data(Info &info) {
	render_register(info);
	render_user_data_segment(info);
	return (true);
}

bool	render_register(Info &info) {
	// draw text -------------------------------------------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Register", (Vector2){ screenWidth-200, 55 }, 20.0f, 1.0f, BLACK);
	// draw text -------------------------------------------------------------------------------------------------------------------------------

	// draw register sector --------------------------------------------------------------------------------------------------------------------
		DrawRectangle(screenWidth-200, 80, 177, 350, Fade(LIGHTGRAY, 0.5f));
		DrawRectangleLines(screenWidth-200, 80, 177, 350, GRAY);
	// draw register sector --------------------------------------------------------------------------------------------------------------------

	// draw register contents ------------------------------------------------------------------------------------------------------------------
		for (size_t i=0; i<32; i++) {
			string	reg = string("R") + to_string(i);
			string	reg_text = string("[") + register_text[i] + string("]");
			string	value = string("=   0x") + n2hexstr(info.registerValues[i]);
			DrawTextEx(GetFontDefault(), reg.c_str(), (Vector2){ screenWidth-200+10, (float)90+(i*10) }, 10.0f, 1.0f, BLACK);
			DrawTextEx(GetFontDefault(), reg_text.c_str(), (Vector2){ screenWidth-200+40, (float)90+(i*10) }, 10.0f, 1.0f, BLACK);
			DrawTextEx(GetFontDefault(), value.c_str(), (Vector2){ screenWidth-200+85, (float)90+(i*10) }, 10.0f, 1.0f, BLACK);
		}
	// draw register contents ------------------------------------------------------------------------------------------------------------------
	return (true);
}

bool	render_user_data_segment(Info &info) {
	// draw text ------------------------------------------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "User data segment", (Vector2){ screenWidth-200, 440.0f }, 20.0f, 1.0f, BLACK);
	// draw text ------------------------------------------------------------------------------------------------------------------------------

	// draw data segment sector ---------------------------------------------------------------------------------------------------------------
		float	btnHeight = info.button.get_btn_bounds().y;
		DrawRectangle(screenWidth-200, 465, 177, btnHeight-510, Fade(LIGHTGRAY, 0.5f));
		DrawRectangleLines(screenWidth-200, 465, 177, btnHeight-510, GRAY);
	// draw data segment sector ---------------------------------------------------------------------------------------------------------------

	// draw data segment contents ------------------------------------------------------------------------------------------------------------
		for (size_t i=0; i<9+(SIZE_FACTOR-7)*7&&i<info.mem.size(); i++) {
			string	address = string("[0x") + n2hexstr(info.mem[i].address) + string("]");
			string	value = string("0x") + n2hexstr(info.mem[i].value);
			DrawTextEx(GetFontDefault(), address.c_str(), (Vector2){ screenWidth-200+10, (float)475+(i*15) }, 10.0f, 1.0f, BLACK);
			DrawTextEx(GetFontDefault(), value.c_str(), (Vector2){ screenWidth-200+100, (float)475+(i*15) }, 10.0f, 1.0f, BLACK);
		}
	return (true);
}

template <typename I> std::string n2hexstr(I w, size_t hex_len) {
    static const char* digits = "0123456789abcdef";
    std::string rc(hex_len,'0');
    for (size_t i=0, j=(hex_len-1)*4 ; i<hex_len; ++i,j-=4)
        rc[i] = digits[(w>>j) & 0x0f];
    return rc;
}