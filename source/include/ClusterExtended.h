#ifndef ClusterExtended_H
#define ClusterExtended_H 1

#include "CaloHitExtended.h"
#include "TrackExtended.h"
#include "EVENT/Cluster.h"
#include "HelixClass.h"

using namespace lcio;

class TrackExtended;
typedef std::vector<TrackExtended*> TrackExtendedVec;

class CaloHitExtended;
typedef std::vector<CaloHitExtended*> CaloHitExtendedVec;

class ClusterExtended;
typedef std::vector<ClusterExtended*> ClusterExtendedVec;

/**
 * Class extending native LCIO class Cluster. <br>
 * Class ClusterExtended is used in TrackwiseClustering <br>
 * and Wolf processors. <br>
 * @author A. Raspereza (DESY)<br>
 * @version $Id: ClusterExtended.h,v 1.4 2006-02-22 14:41:41 owendt Exp $<br>
 */

class ClusterExtended {

 public:

    ClusterExtended();
    ClusterExtended( Cluster * cluster );
    ClusterExtended(CaloHitExtended * calohit);
    ClusterExtended(TrackExtended * track);

    //objects do not own pointers, we can use defaults, or they do own and
    //things leak like mad because the dtor is not correctly implemented
    ClusterExtended(ClusterExtended& clusterextended) = default;
    ClusterExtended& operator=(ClusterExtended& clusterextended) = default;

    ~ClusterExtended();
    
    CaloHitExtendedVec & getCaloHitExtendedVec();
    TrackExtendedVec & getTrackExtendedVec();
    const float* getStartingPoint();
    const float* getDirection();
    void setStartingPoint(float* sPoint);
    void setDirection(float* direct);
    void addCaloHitExtended(CaloHitExtended * calohit);
    void addTrackExtended(TrackExtended * track);
    void setType( int type );
    int getType();

    void Clear();

    void setCluster(Cluster * cluster);
    Cluster * getCluster();

    void setAxis(float * axis);
    float * getAxis();

    void setEccentricity( float eccentricity);
    float getEccentricity();

    void setHelix(HelixClass helix);
    HelixClass & getHelix();

    void setHelixChi2R(float helixChi2);
    float getHelixChi2R();

    void setHelixChi2Z(float helixChi2);
    float getHelixChi2Z();

    void setPosition(float * position);
    float * getPosition();

    void setLowEdge(float * lowEdge);
    float * getLowEdge();
    void setUpEdge(float * upEdge);
    float * getUpEdge();


 private:

    TrackExtendedVec _trackVector{};
    CaloHitExtendedVec _hitVector{};
    float _startingPoint[3];
    float _direction[3];

    int _type=0;
    Cluster * _cluster=NULL;

    float _axis[3];
    float _position[3];
    float _eccentricity=0.0;

    HelixClass _helix{};
    float _helixChi2R=0.0;
    float _helixChi2Z=0.0;
    
    float _lowEdge[3];
    float _upEdge[3];


};

#endif
