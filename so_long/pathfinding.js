class Game {
    height = null;
    width = null;
    map = [];
    points = [];
    startPoint = null;
    endPoint = null;
    nbrItems = 0;
    hasValidExit = false;
    hasValidItems = false;

    currentPoint = null;
    lastPoint = null;

    constructor() {
        this.map = [
            ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
            ["1", "0", "0", "1", "1", "0", "0", "0", "0", "0", "1", "C", "1"],
            ["1", "1", "0", "0", "0", "0", "1", "1", "1", "0", "0", "1", "1"],
            ["1", "P", "0", "0", "1", "1", "E", "0", "0", "0", "0", "0", "1"],
            ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"]
        ];
        this.height = this.map.length;
        this.width = this.map[0].length;
        this.createPoints();
        //console.log(this.startPoint)
        this.visitNode(this.startPoint.x, this.startPoint.y, 0)
        console.log(this.hasValidExit)
        console.log(this.hasValidItems)
        console.log("==============")
        //console.log(this.findPoint(this.startPoint.x, this.startPoint.y));
    }

    visitNode(x, y, items) {
        let exit = false;
        const point = this.findPoint(x, y);
        console.log(point);
        if (x < 0 || y < 0 || x >= this.width || y >= this.height)
		    return (false);
        if (!point || (point && point.treated))
            return false;
        if (point.value === "1")
            return false;
        if (point.value === "C")
            items++;
        if (point.value === "E")
            this.hasValidExit = true;
        if (items === this.nbrItems)
            this.hasValidItems = true;
        point.treated = true;
        this.visitNode(x, y + 1, items);
        this.visitNode(x, y - 1, items);
        this.visitNode(x + 1, y, items);
        this.visitNode(x - 1, y, items);
        return (exit);
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
                if (point.value === "C") {
                    this.nbrItems++;
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
}

class Point {
    x = null;
    y = null;
    value = null;
    treated = false;

    constructor(x, y, value) {
        this.x = x;
        this.y = y;
        this.value = value;
    }

    isEqualTo(point) {
        return this.x === point.x && this.y === point.y && this.value === point.value;
    }
}
new Game();