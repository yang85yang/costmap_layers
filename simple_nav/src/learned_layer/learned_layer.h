#ifndef LEARNED_LAYER_H_
#define LEARNED_LAYER_H_
#include <ros/ros.h>
#include <costmap_2d/costmap_layer.h>
#include <costmap_2d/layered_costmap.h>
#include <costmap_2d/GenericPluginConfig.h>
#include <dynamic_reconfigure/server.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include "simple_nav/RealGrid.h"
#include <string>

namespace simple_layer_namespace
{

	class LearnedLayer : public costmap_2d::CostmapLayer
	{
	public:

		LearnedLayer();

		virtual void onInitialize();

		virtual void updateBounds(double origin_x, 
									double origin_y, 
									double origin_yaw, 
									double* min_x, 
									double* min_y, 
									double* max_x,
									double* max_y);

		virtual void updateCosts(costmap_2d::Costmap2D& master_grid, 
									int min_i, 
									int min_j, 
									int max_i, 
									int max_j);

		bool isDiscretized() { return true; }

		virtual void matchSize();


	private:
		void reconfigureCB(costmap_2d::GenericPluginConfig &config, uint32_t level);

		void load();

		dynamic_reconfigure::Server<costmap_2d::GenericPluginConfig> *dsrv_;

		std::string costmap_path_;

		bool was_enabled_;
	};
}
#endif