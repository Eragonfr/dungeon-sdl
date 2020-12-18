#include "../include/game_unix.h"

#ifdef __unix__

int match(const char* string, const char* pattern) {
	regex_t re;
	if (regcomp(&re, pattern, REG_EXTENDED | REG_NOSUB) != 0) {
		return 0;
	}
	int status = regexec(&re, string, 0, NULL, 0);
	regfree(&re);
	if (status != 0) {
		return 0;
	}
	return 1;
}

int GAME_ImportAssetsAll(Game* game, const char* basePath, const char* filter) {
	//const char* regex = "[^\\s]+(\\.(jpe?g|png|gif|bmp))$";
	char path[1000];
	struct dirent* dp;
	DIR* dir = opendir(basePath);

	if (!dir) {
		return 0;
	}

	while ((dp = readdir(dir)) != NULL) {
		if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
			strcpy(path, basePath);
			strcat(path, "/");
			strcat(path, dp->d_name);

			DIR* secdir = opendir(path);
			if (!secdir) {
				char* texId = filepathToTextureId(path, true, "/");
				TEXMGR_Load(game->textureManager, texId, path);
			}

			GAME_ImportAssetsAll(game, path, filter);
		}
	}

	closedir(dir);
	return 1;
}

#endif
