#include "header.hpp"

namespace data
{
Json::Value cfg;
std::map<std::string, sf::Texture> img_holder;

void create_config()
{
    const char *s =
        R"V0G0N({
    "mode": 1,
    "liveID": 22661866,
    "memeDuration": 2500,
    "decoration": {
        "leftHanded": false,
        "rgb": [0, 255, 0],
        "offsetX": [0, 11],
        "offsetY": [0, -65],
        "scalar": [1.0, 1.0],
		"framerateLimit":60,
		"topWindow": false,
		"armLineColor": [62, 3, 3],
		"emoticonKeep": true,
		"emoticonClear":[27],
        "correct":100,
        "mouse_force_move":false
	},
    "workarea":{
        "workarea":false,
        "top_left":[0,0],
        "right_bottom":[1920,1080]
    },
	"morekeys":{
		"mouse":true,
		"mouse_left": [1],
		"mouse_right":[2],
		"keybord":[48,	57,	56,	55,	54,	53,	52,	51,	50,	49,	192,	80,	79,	73,	85,	89,	84,	82,	69,	87,	81,	191,	77,	78,	66,	86,	67,	76,	75,	74,	72,	71,	70,	65,	83,	68,	88,	90,	113,	27,	46,	8,	13,	32,	18,	16,	17,	20,	9,91],
		"hand":[   48,	57,	56,	55,	54,	53,	52,	51,	50,	49,	192,	80,	79,	73,	85,	89,	84,	82,	69,	87,	81,	191,	77,	78,	66,	86,	67,	76,	75,	74,	72,	71,	70,	65,	83,	68,	88,	90,	113,	27,	46,	8,	13,	32,	18,	16,	17,	20,	9,91],
		"face":[112,113,114,115, 116,117,118,119],
		"acce":[120,121, 122,123],
		"meme":[],
        "sounds":[]
	}


})V0G0N";
    std::string error;
    Json::CharReaderBuilder cfg_builder;
    Json::CharReader *cfg_reader = cfg_builder.newCharReader();
    cfg_reader->parse(s, s + strlen(s), &cfg, &error);
}

void error_msg(std::string error, std::string title)
{
    if (MessageBoxA(NULL, error.c_str(), title.c_str(), MB_ICONERROR | MB_RETRYCANCEL) == IDCANCEL)
        exit(0);
}

bool update(Json::Value &cfg_default, Json::Value &cfg)
{
    bool is_update = true;
    for (const auto &key : cfg.getMemberNames())
        if (cfg_default.isMember(key))
        {
            if (cfg_default[key].type() != cfg[key].type())
            {
                error_msg("Value type error in config.json", "Error reading configs");
                return false;
            }
            if (cfg_default[key].isArray())
                for (Json::Value &v : cfg[key])
                    if (v.type() != cfg_default[key][0].type())
                    {
                        error_msg("Value type error in config.json", "Error reading configs");
                        return false;
                    }
            if (cfg_default[key].isObject())
                is_update &= update(cfg_default[key], cfg[key]);
            else
                cfg_default[key] = cfg[key];
        }
    return is_update;
}

bool init()
{
    while (true)
    {
        create_config();
        std::ifstream cfg_file("config.json", std::ifstream::binary);
        if (!cfg_file.good())
            break;
        std::string cfg_string((std::istreambuf_iterator<char>(cfg_file)), std::istreambuf_iterator<char>()), error;
        Json::CharReaderBuilder cfg_builder;
        Json::CharReader *cfg_reader = cfg_builder.newCharReader();
        Json::Value cfg_read;
        if (!cfg_reader->parse(cfg_string.c_str(), cfg_string.c_str() + cfg_string.size(), &cfg_read, &error))
            error_msg("Syntax error in config.json:\n" + error, "Error reading configs");
        else if (update(cfg, cfg_read))
            break;
    }

    img_holder.clear();

    int mode = data::cfg["mode"].asInt();
    switch (mode)
    {
	case 1:
        return morekeys::init();
    default:
        error_msg("Mode value is not correct", "Error reading configs");
        return false;
    }
}

sf::Texture &load_texture(std::string path)
{
    if (img_holder.find(path) == img_holder.end())
        while (!img_holder[path].loadFromFile(path))
            error_msg("Cannot find file " + path, "Error importing images");
    return img_holder[path];
}

sf::Texture &load_texture2(std::string path)
{
	if (img_holder.find(path) == img_holder.end())
		img_holder[path].loadFromFile(path);
	return img_holder[path];
}
}; // namespace data
