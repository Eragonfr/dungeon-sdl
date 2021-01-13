#include "game_win.h"

#ifdef _WIN32

#pragma comment(lib, "shlwapi.lib")

int findFilesRecursively(Game* game, LPCTSTR lpFolder, LPCTSTR lpFilePattern)
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
            // if the file is a directory
            if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (FindFileData.cFileName[0] == '.') { continue; }

                // load all subdirectories in the current directory
                PathCombine(szFullPattern, lpFolder, FindFileData.cFileName);
                findFilesRecursively(game, szFullPattern, lpFilePattern);
            }
        } 
        // while there is a next file (e.g folder)
        while (FindNextFile(hFindFile, &FindFileData));
        
        // close find handle
        FindClose(hFindFile);
    }

    // now we are going to look for the matching files 
    PathCombine(szFullPattern, lpFolder, lpFilePattern);
    hFindFile = FindFirstFile(szFullPattern, &FindFileData);

    if (hFindFile != INVALID_HANDLE_VALUE)
    {
        do
        {
            // if the file isn't a directory
            if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                // found a file; do something with it 
                PathCombine(szFullPattern, lpFolder, FindFileData.cFileName);

                // convert TCHAR to char*
                char texPath[MAX_PATH];
                size_t nNumCharConverted;
                wcstombs_s(&nNumCharConverted, texPath, MAX_PATH, szFullPattern, MAX_PATH);
                
                char* texId = filePathToTextureId(texPath, true, "\\");
                TEXMGR_Load(game->textureManager, texId, texPath);
            }
        }
        // while there is a next file corresponding to the filter
        while (FindNextFile(hFindFile, &FindFileData));

        FindClose(hFindFile);
    }

    return importedLineCount;
}

int GAME_ImportAssetsAll(Game* game, const char* dir)
{
    // call FindFilesRecursively with dir and fileter converted as TCHAR
    const char* filter = "*.png"

    TCHAR c_dir[MAX_PATH];
    TCHAR c_filter[520];

    swprintf(c_dir, MAX_PATH, L"%hs", dir);
    swprintf(c_filter, MAX_PATH, L"%hs", filter);

    return findFilesRecursively(game, c_dir, c_filter);
}

#endif
