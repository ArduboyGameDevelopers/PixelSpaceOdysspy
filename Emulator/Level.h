#ifndef LEVEL_H
#define LEVEL_H

#include "tilemap.h"

#include "Object.h"
#include "Tileset.h"
#include "LevelCharacter.h"

#include <QtGlobal>
#include <QImage>

class Level : public Object
{
    OBJECT_DEF(Level)

protected:
    Level();

public:
    Level(uint8_t* indices, uint8_t rows, uint8_t cols);
    virtual ~Level();
    
public:
    static Level* readFromFile(const QString &filename);
    static Level* readFromImage(const QImage &image, const TileSet* tileSet);
    void writeToFile(const QString &filename);
    
public:
    static Level *current() { return _currentLevel; }
    static void setCurrent(Level *level);

public:
    void addEnemy(CharacterType type, int x, int y, CharacterDir dir);
    void resize(uint8_t rows, uint8_t cols);

public:
    inline LevelCharacter player() const { return _player; }
    inline void setPlayerPos(int x, int y) { _player.setPos(x, y); }
    inline void setPlayerDir(CharacterDir dir) { _player.setDirection(dir); }
    
    inline const QList<LevelCharacter> enemies() const { return _enemies; }
    inline uint8_t* indices() const { return _indices; }

    inline uint8_t tileSetId() const { return _tileSetId; }
    inline void setTileSetId(uint8_t tileSetId) { _tileSetId = tileSetId; }

    inline uint8_t rows() const { return _rows; }
    inline void setRows(uint8_t rows) { _rows = rows; }

    inline uint8_t cols() const { return _cols; }
    inline void setCols(uint8_t cols) { _cols = cols; }

protected:
    inline void setIndices(uint8_t* indices) { _indices = indices; }
    
private:
    static Level * _currentLevel;
    LevelCharacter _player;
    QList<LevelCharacter> _enemies;
    uint8_t  _tileSetId;
    uint8_t* _indices;
    uint8_t  _rows;
    uint8_t  _cols;
};

#endif // LEVEL_H
