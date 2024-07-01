#ifndef TREE_PRINTER_HPP
#define TREE_PRINTER_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QString>
#include <sstream>
#include "node.hpp"

// Forward declaration of Tree template class
template <typename T, int K>
class Tree;

template <typename T, int K>
class TreePrinter : public QWidget {
public:
    TreePrinter(QWidget *parent = nullptr) : QWidget(parent) {
        scene = new QGraphicsScene(this);
        view = new QGraphicsView(scene, this);
        view->setRenderHint(QPainter::Antialiasing);
        view->setAlignment(Qt::AlignCenter);

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(view);
        setLayout(layout);
    }

    void print(Tree<T, K> &tree) {
        draw(400, 50, tree.getRoot());
        view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
        show();
    }

private:
    QGraphicsScene *scene;
    QGraphicsView *view;

    void draw(int x, int y, Node<T>* node, int circleSize = 75, int horizontalSpacing = 350, int verticalSpacing = 150) const {
        if (!node) return;

        // Add the ellipse item to the scene
        scene->addEllipse(x, y, circleSize, circleSize, QPen(Qt::black), QBrush(Qt::white));

        // Add a text item to the scene that contains the node's data
        std::stringstream ss;
        ss << node->get_value();
        QString nodeText = QString::fromStdString(ss.str());
        QGraphicsTextItem* text = scene->addText(nodeText);
        text->setPos(x + circleSize / 2 - text->boundingRect().width() / 2, y + circleSize / 2 - text->boundingRect().height() / 2);

        // Calculate the horizontal spacing between children nodes
        int depthFactor = 1;  // Adjust depth factor if needed
        int adjustedHorizontalSpacing = std::max(horizontalSpacing / depthFactor, circleSize);  // Ensure spacing doesn't become too small

        // Calculate the x position of the first child node
        int childX = x - (node->children.size() - 1) * adjustedHorizontalSpacing / 2;

        // Draw the children nodes
        for (Node<T>* child : node->children) {
            if (child == nullptr) {  // If the child is nullptr, just add the horizontal spacing and continue
                childX += adjustedHorizontalSpacing;
                continue;
            }

            // Draw the line between the parent and the child
            scene->addLine(x + circleSize / 2, y + circleSize, childX + circleSize / 2, y + verticalSpacing, QPen(Qt::black));

            // Recursively draw child nodes with more aggressively adjusted spacing
            draw(childX, y + verticalSpacing, child, circleSize, horizontalSpacing, verticalSpacing);
            childX += adjustedHorizontalSpacing;
        }
    }
};

#endif // TREE_PRINTER_HPP


















