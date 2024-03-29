
#include "lua.h"
#include "lauxlib.h"

#include <dirent.h>
#include <errno.h>
#include <string.h>

static int l_dir(lua_State *L) {
  DIR *dir;
  struct dirent *entry;
  int i;
  const char *path = luaL_checkstring(L, 1);

  /* 디렉터리 열기 */
  dir = opendir(path);
  if (dir == NULL) {
    lua_pushnil(L);
    lua_pushstring(L, strerror(errno));
    return 2;
  }

  /* 결과 테이블 생성*/
  lua_newtable(L);
  i = 1;
  while((entry = readdir(dir)) != NULL) {
    lua_pushnumber(L, i++);
    lua_pushstring(L, entry->d_name);
    lua_settable(L, -3);
  }

  closedir(dir);
  return 1;
}

static const struct luaL_Reg fs[] = {
  {"dir", l_dir},
  {NULL, NULL}
};

int luaopen_lcm_fs (lua_State *L) {
  luaL_register(L, "fs", fs);
  return 1;
}

