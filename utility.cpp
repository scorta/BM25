#include "./header/utility.hpp"

std::string utility::remove_vn_tone(const std::string& s) {
	std::string res{ s };
	res = std::regex_replace(res, std::regex("à|á|ạ|ả|ã|â|ầ|ấ|ậ|ẩ|ẫ|ă|ằ|ắ|ặ|ẳ|ẵ|/g"), "a");
	res = std::regex_replace(res, std::regex("è|é|ẹ|ẻ|ẽ|ê|ề|ế|ệ|ể|ễ|/g"), "e");
	res = std::regex_replace(res, std::regex("ì|í|ị|ỉ|ĩ|/g"), "i");
	res = std::regex_replace(res, std::regex("ò|ó|ọ|ỏ|õ|ô|ồ|ố|ộ|ổ|ỗ|ơ|ờ|ớ|ợ|ở|ỡ|/g"), "o");
	res = std::regex_replace(res, std::regex("ù|ú|ụ|ủ|ũ|ư|ừ|ứ|ự|ử|ữ|/g"), "u");
	res = std::regex_replace(res, std::regex("ỳ|ý|ỵ|ỷ|ỹ|/g"), "y");
	res = std::regex_replace(res, std::regex("đ|/g"), "d");
	return res;
}

std::string utility::remove_meaningless_char(const std::string& s) {
	std::string res{ s };
	res = std::regex_replace(res, std::regex("-|\\[|\\]|\\(|\\)|\\{|\\}|\\?|\\.|\\,|\\`|\\!|\\/|\\'|/g"), " ");
	return res;
}