#include "Graph.h"
using namespace std;

//Graph::Graph() {}

Graph::Graph(ifstream & ifs) {
    int numNodes, numEdges;
    ifs >> numNodes >> numEdges;

    string vertexName;
    for (int i = 0; i < numNodes; i++) {
        ifs >> vertexName;
        Vertex newVertex;
        newVertex.label = vertexName;
        vertices.push_back(newVertex);
    }

    string v1, v2;
    int cost;
    for (int i = 0; i < numEdges; i++) {
        ifs >> v1 >> v2 >> cost;
        for (unsigned j = 0; j < vertices.size(); j++) {
            if (vertices.at(j).label == v1) {
                for (unsigned k = 0; k < vertices.size(); k++) {
                    if (vertices.at(k).label == v2) {
                        pair<int, int> p(k, cost);
                        vertices.at(j).neighbors.push_back(p);
                    }
                }
            }
        }
    }
}

Graph::~Graph() { 
    while (vertices.size() != 0) {
        vertices.pop_back();
    }
}

void Graph::output_graph(const string & outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if (!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }

    outFS<<"digraph G {"<<endl;

    for (unsigned i = 0; i < vertices.size(); i++) {
    	if (vertices.at(i).distance != INT_MAX) {
            outFS << vertices.at(i).label << "[label = \"" << vertices.at(i).label << ", " << vertices.at(i).distance << "\"]" << endl;
    	}
     	if (!vertices.at(i).neighbors.empty()) {
     	    list<pair<int, int> > ::iterator it = vertices.at(i).neighbors.begin();
     		while (it != vertices.at(i).neighbors.end()) {
     				if (vertices.at(i).distance!= INT_MAX) {
     		            outFS << vertices.at(i).label << " -> " << vertices.at(it->first).label << endl;
     				}
     		    it++;
     		}
     	}
     	    
    }

    outFS<<"}";
    outFS.close();
    
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tpng " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
    return;
}

void Graph::bfs() {
    for (unsigned i = 0; i < vertices.size(); i++) { // default for all vertices
		vertices.at(i).distance = INT_MAX;
        vertices.at(i).color = "WHITE";
		vertices.at(i).prev = nullptr;
	}
    vertices.at(0).color = "GRAY"; // setting start vertex
	vertices.at(0).distance = 0;

    queue<Vertex> vertexQueue;
    vertexQueue.push(vertices.at(0));
    Vertex currentVertex;
    while (vertexQueue.size() != 0) {
        currentVertex = vertexQueue.front();
        vertexQueue.pop();
        list<pair<int, int> >::iterator it = currentVertex.neighbors.begin();
        while (it != currentVertex.neighbors.end()) {
            cout << "TEST3";
            if (vertices.at(it->first).color == "WHITE") {
                vertices.at(it->first).color = "GRAY";
                vertices.at(it->first).distance = currentVertex.distance + it->second;
                for (unsigned j = 0; j < vertices.size(); j++) {
                    if (vertices.at(j).label == currentVertex.label ) {
                        vertices.at(it->first).prev = &vertices.at(j);
                    }
                }
                vertexQueue.push(vertices.at(it->first));
            }
            it++;
        }
    }
}