class Map {
    height = null;
    width = null;
    map = [];
    points = [];
    startPoint = null;
    endPoint = null;

    currentPoint = null;
    lastPoint = null;

    constructor() {
        this.map = [
            ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
            ["1", "0", "0", "1", "0", "0", "0", "0", "0", "0", "0", "C", "1"],
            ["1", "0", "0", "0", "0", "1", "1", "1", "1", "1", "0", "0", "1"],
            ["1", "P", "0", "0", "1", "1", "E", "0", "0", "0", "0", "0", "1"],
            ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"]
        ];
        this.height = this.map.length;
        this.width = this.map[0].length;
        this.createPoints();
        console.log(this.goLeft(this.currentPoint));
    }

    createPoints() {
        let i = 0;
        let j = 0;
        while (i < this.height)
        {
            j = 0;
            while (j < this.width)
            {
                const point = new Point(j, i, this.map[i][j]);
                if (point.value === "P") {
                    this.currentPoint = point;
                    this.startPoint = point;
                }
                if (point.value === "E") {
                    this.endPoint = point;
                }
                this.points.push(point);
                j++;
            }
            i++;
        }
    }

    findPoint(x, y) {
        return this.points.find(p => p.x === x && p.y === y);
    }

    goLeft(currentPoint) {
        const x = currentPoint.x;
        const y = currentPoint.y;
        console.log("Futur new pos: x,y "+ (x-1) + ","+y);
        console.log(this.points);
        console.log(this.findPoint(x-1, y));
        if (this.points[y][x - 1] && this.points[y][x - 1].value !== "E") {
            this.currentPoint = this.map[y][x - 1];
            this.lastPoint = currentPoint;
            return true;
        }
        return false;
    }
}

class Point {
    x = null;
    y = null;
    value = null;

    constructor(x, y, value) {
        this.x = x;
        this.y = y;
        this.value = value;
    }

    isEqualTo(point) {
        return this.x === point.x && this.y === point.y && this.value === point.value;
    }
}
new Map();