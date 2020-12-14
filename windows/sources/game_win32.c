#include "../../windows/headers/game_win32.h"

#ifdef _WIN32

#pragma comment(lib, "Shlwapi.lib")

int FindFilesRecursively(Game* game, LPCTSTR lpFolder, LPCTSTR lpFilePattern)
{
    int importedLineCount = 0;

    TCHAR szFullPattern[MAX_PATH];
    WIN32_FIND_DATA FindFileData;
    HANDLE hFindFile;

    // first we are going to process any subdirectories 
    PathCombine(szFullPattern, lpFolder, _T("*"));
    hFindFile = FindFirstFile(szFullPattern, &FindFileData);
    
    if (hFindFile != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (FindFileData.cFileName[0] == '.') { continue; }

                PathCombine(szFullPattern, lpFolder, FindFileData.cFileName);
                FindFilesRecursively(game, szFullPattern, lpFilePattern);
            }
        }
        while (FindNextFile(hFindFile, &FindFileData));
        FindClose(hFindFile);
    }

    // now we are going to look for the matching files 
    PathCombine(szFullPattern, lpFolder, lpFilePattern);
    hFindFile = FindFirstFile(szFullPattern, &FindFileData);
    if (hFindFile != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                // found a file; do something with it 
                PathCombine(szFullPattern, lpFolder, FindFileData.cFileName);

                TCHAR szWideString[MAX_PATH];
                char szString[MAX_PATH];
                size_t nNumCharConverted;
                wcstombs_s(&nNumCharConverted, szString, MAX_PATH,
                    szWideString, MAX_PATH);

                int n = TEXMGR_Load(game->textureManager, "placeholder", szString);
                SDL_Texture* tex = IMG_Load(szString);

                printf("%d", tex);





                // success/error
                LOGGER_LogInformation("Imported resource: %ws", szFullPattern);
            }
        }
        while (FindNextFile(hFindFile, &FindFileData));

        FindClose(hFindFile);
    }

    return importedLineCount;
}

int GAME_ImportAssetsAll(Game* game, const char* dir, const char* filter)
{
    TCHAR c_dir[MAX_PATH];
    TCHAR c_filter[520];

    swprintf(c_dir, MAX_PATH, L"%hs", dir);
    swprintf(c_filter, MAX_PATH, L"%hs", filter);

    return FindFilesRecursively(game, c_dir, c_filter);
}

#endif