## porting workflow

```mermaid
graph TB
    subgraph ACOS
        direction TB
        style Excutor stroke-dasharray: 5 5
        
        App[App] --> Excutor[Excutor]
        Excutor[Excutor] --> Runnable[Runnable]
        Runnable --> ServiceIntance[ServiceIntance]
        ServiceIntance --> Server/Client[Server/Client]
        Server/Client --> ServiceType[ServiceType]
        ServiceType --> DataType[DataType]
    end

    subgraph ROS
        direction TB
        style placeholder_0 stroke-dasharray: 5 5
        style placeholder_1 stroke-dasharray: 5 5
        style placeholder_2 stroke-dasharray: 5 5

        Container[Container] --> placeholder_0[ <br> ]
        placeholder_0[ <br> ] --> Node/Plugin[Node/Plugin]
        Node/Plugin --> placeholder_1[ <br> ]
        placeholder_1 --> Server/Client_ROS[Server/Client]
        Server/Client_ROS --> placeholder_2[ <br> ]
        placeholder_2 --> DataType_ROS[DataType]
    end
```

```graphviz
digraph finite_state_machine {
    rankdir=LR;
    size="8,5"

    node [shape = doublecircle]; S;
    node [shape = point ]; qi

    node [shape = circle];
    qi -> S;
    S  -> q1 [ label = "a" ];
    S  -> S  [ label = "a" ];
    q1 -> S  [ label = "a" ];
    q1 -> q2 [ label = "ddb" ];
    q2 -> q1 [ label = "b" ];
    q2 -> q2 [ label = "b" ];
}
```

| Node | Subscribers | Publishers |
|:-----|:------------|:-----------|
| /aggregator_node | /diagnostics<br>/parameter_events | /diagnostics_agg<br>/diagnostics_toplevel_state<br>/parameter_events<br>/rosout |
| /autoware_api/external/autoware_iv_adaptor | /parameter_events | /rosout |
| /autoware_api/external/cpu_usage | /parameter_events<br>/system/system_monitor/cpu_monitor/cpu_usage | /api/external/get/cpu_usage<br>/parameter_events<br>/rosout |
| /autoware_api/external/diagnostics | /parameter_events | /api/external/get/diagnostics<br>/parameter_events<br>/rosout |
| /autoware_api/external/door | /parameter_events<br>/vehicle/status/door_status | /api/external/get/door<br>/parameter_events<br>/rosout |
| /autoware_api/external/emergency | /api/autoware/get/emergency<br>/parameter_events | /api/external/get/emergency<br>/parameter_events<br>/rosout |
| /autoware_api/external/engage | /api/autoware/get/engage<br>/autoware/state<br>/parameter_events | /api/external/get/engage<br>/parameter_events<br>/rosout |
| /autoware_api/external/fail_safe_state | /parameter_events<br>/system/fail_safe/mrm_state | /api/external/get/fail_safe/state<br>/parameter_events<br>/rosout |
| /autoware_api/external/initial_pose | /parameter_events | /parameter_events<br>/rosout<br>/service_log |
| /autoware_api/external/map | /api/autoware/get/map/info/hash<br>/parameter_events | /api/external/get/map/info/hash<br>/parameter_events<br>/rosout |
| /autoware_api/external/metadata_packages | /parameter_events | /parameter_events<br>/rosout |
| /autoware_api/external/operator | /api/autoware/get/observer<br>/api/autoware/get/operator<br>/parameter_events | /api/external/get/observer<br>/api/external/get/operator<br>/parameter_events<br>/rosout |
| /autoware_api/external/route | /api/routing/route<br>/parameter_events | /api/external/get/route<br>/parameter_events<br>/rosout<br>/service_log |
| /autoware_api/external/rtc_controller | /parameter_events<br>/planning/cooperate_status/avoidance_left<br>/planning/cooperate_status/avoidance_right<br>/planning/cooperate_status/blind_spot<br>/planning/cooperate_status/crosswalk<br>/planning/cooperate_status/detection_area<br>/planning/cooperate_status/intersection<br>/planning/cooperate_status/lane_change_left<br>/planning/cooperate_status/lane_change_right<br>/planning/cooperate_status/no_stopping_area<br>/planning/cooperate_status/occlusion_spot<br>/planning/cooperate_status/pull_out<br>/planning/cooperate_status/pull_over<br>/planning/cooperate_status/traffic_light<br>/planning/cooperate_status/virtual_traffic_light | /api/external/get/rtc_status<br>/parameter_events<br>/rosout |
| /autoware_api/external/service | /parameter_events | /api/external/get/service<br>/parameter_events<br>/rosout |
| /autoware_api/external/start | /api/external/get/operator<br>/parameter_events | /parameter_events<br>/rosout |
| /autoware_api/external/vehicle_status | /control/command/control_cmd<br>/parameter_events<br>/vehicle/status/gear_status<br>/vehicle/status/hazard_lights_status<br>/vehicle/status/steering_status<br>/vehicle/status/turn_indicators_status<br>/vehicle/status/velocity_status | /api/external/get/command/selected/vehicle<br>/api/external/get/vehicle/status<br>/parameter_events<br>/rosout |
| /autoware_api/external/velocity | /parameter_events | /parameter_events<br>/rosout |
| /autoware_api/external/version | /parameter_events | /parameter_events<br>/rosout |
| /autoware_api/internal/autoware_iv_adaptor | /parameter_events | /rosout |
| /autoware_api/internal/crosswalk_states | /parameter_events | /parameter_events<br>/rosout |
| /autoware_api/internal/intersection_states | /parameter_events | /parameter_events<br>/rosout |
| /autoware_api/internal/iv_msgs | /autoware/state<br>/parameter_events<br>/perception/object_recognition/tracking/objects<br>/planning/scenario_planning/trajectory<br>/system/fail_safe/mrm_state<br>/vehicle/status/control_mode | /api/iv_msgs/autoware/state<br>/api/iv_msgs/perception/object_recognition/tracking/objects<br>/api/iv_msgs/planning/scenario_planning/trajectory<br>/api/iv_msgs/vehicle/status/control_mode<br>/parameter_events<br>/rosout |
| /autoware_api/internal/operator | /api/autoware/get/emergency<br>/control/current_gate_mode<br>/control/external_cmd_selector/current_selector_mode<br>/parameter_events<br>/vehicle/status/control_mode | /api/autoware/get/observer<br>/api/autoware/get/operator<br>/control/gate_mode_cmd<br>/parameter_events<br>/rosout |
| /autoware_api/internal/traffic_signals | /parameter_events | /parameter_events<br>/rosout |
| /autoware_api/internal/velocity | /parameter_events<br>/planning/scenario_planning/current_max_velocity | /api/autoware/get/velocity_limit<br>/parameter_events<br>/planning/scenario_planning/max_velocity_default<br>/rosout |
| /awapi/autoware_engage_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/awapi_awiv_adapter_node | /api/iv_msgs/autoware/state<br>/awapi/vehicle/put/stop<br>/awapi/vehicle/put/velocity<br>/control/command/control_cmd<br>/control/current_gate_mode<br>/diagnostics_agg<br>/localization/kinematic_state<br>/parameter_events<br>/planning/scenario_planning/current_max_velocity<br>/planning/scenario_planning/lane_driving/lane_change_available<br>/planning/scenario_planning/lane_driving/lane_change_candidate_path<br>/planning/scenario_planning/lane_driving/lane_change_ready<br>/planning/scenario_planning/lane_driving/obstacle_avoidance_candidate_trajectory<br>/planning/scenario_planning/lane_driving/obstacle_avoidance_ready<br>/planning/scenario_planning/status/infrastructure_commands<br>/planning/scenario_planning/status/stop_reasons<br>/planning/scenario_planning/trajectory<br>/sensing/gnss/ublox/nav_sat_fix<br>/system/emergency/hazard_status<br>/system/fail_safe/mrm_state<br>/system/v2x/virtual_traffic_light_states<br>/vehicle/status/battery_charge<br>/vehicle/status/control_mode<br>/vehicle/status/gear_status<br>/vehicle/status/hazard_lights_status<br>/vehicle/status/steering_status<br>/vehicle/status/turn_indicators_status | /awapi/autoware/get/status<br>/awapi/lane_change/get/status<br>/awapi/object_avoidance/get/status<br>/awapi/tmp/infrastructure_commands<br>/awapi/tmp/virtual_traffic_light_states<br>/awapi/vehicle/get/status<br>/parameter_events<br>/planning/scenario_planning/max_velocity_default<br>/rosout |
| /awapi/awapi_relay_container | /parameter_events | /rosout |
| /awapi/crosswalk_status_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/expand_stop_range_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/external_approval_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/force_approval_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/force_available_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/force_lane_change_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/intersection_status_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/lane_change_approval_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/nearest_traffic_signal_relay | /parameter_events<br>/planning/scenario_planning/lane_driving/behavior_planning/debug/traffic_signal | /awapi/traffic_light/get/nearest_traffic_signal<br>/parameter_events<br>/rosout |
| /awapi/obstacle_avoid_approval_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/overwrite_traffic_signals_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/pose_initialization_request_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/predict_object_relay | /parameter_events<br>/perception/object_recognition/objects | /awapi/prediction/get/objects<br>/parameter_events<br>/rosout |
| /awapi/put_goal_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/put_route_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/ready_module_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/route_relay | /parameter_events<br>/planning/mission_planning/route | /awapi/autoware/get/route<br>/parameter_events<br>/rosout |
| /awapi/running_modules_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/speed_exceeded_relay | /parameter_events<br>/planning/scenario_planning/motion_velocity_smoother/stop_speed_exceeded | /awapi/autoware/get/stop_speed_exceeded<br>/parameter_events<br>/rosout |
| /awapi/traffic_signal_relay | /parameter_events | /parameter_events<br>/rosout |
| /awapi/transform_listener_impl_56a5bfd08da8 | /parameter_events<br>/tf<br>/tf_static | /rosout |
| /awapi/vehicle_engage_relay | /parameter_events | /parameter_events<br>/rosout |
| /control/control_container | /parameter_events | /rosout |
| /control/external_cmd_converter | /control/current_gate_mode<br>/external/selected/external_control_cmd<br>/external/selected/gear_cmd<br>/external/selected/heartbeat<br>/localization/kinematic_state<br>/parameter_events | /api/external/get/command/selected/control<br>/diagnostics<br>/external/selected/control_cmd<br>/parameter_events<br>/rosout |
| /control/external_cmd_selector | /api/external/set/command/local/control<br>/api/external/set/command/local/heartbeat<br>/api/external/set/command/local/shift<br>/api/external/set/command/local/turn_signal<br>/api/external/set/command/remote/control<br>/api/external/set/command/remote/heartbeat<br>/api/external/set/command/remote/shift<br>/api/external/set/command/remote/turn_signal<br>/parameter_events | /control/external_cmd_selector/current_selector_mode<br>/diagnostics<br>/external/selected/external_control_cmd<br>/external/selected/gear_cmd<br>/external/selected/hazard_lights_cmd<br>/external/selected/heartbeat<br>/external/selected/turn_indicators_cmd<br>/parameter_events<br>/rosout |
| /control/operation_mode_transition_manager | /api/autoware/get/engage<br>/control/command/control_cmd<br>/control/current_gate_mode<br>/control/external_cmd_selector/current_selector_mode<br>/control/vehicle_cmd_gate/operation_mode<br>/localization/kinematic_state<br>/parameter_events<br>/planning/scenario_planning/trajectory<br>/vehicle/status/control_mode | /autoware/engage<br>/control/gate_mode_cmd<br>/control/operation_mode_transition_manager/debug_info<br>/parameter_events<br>/rosout<br>/service_log<br>/system/operation_mode/state |
| /control/shift_decider | /autoware/state<br>/control/trajectory_follower/control_cmd<br>/parameter_events | /control/shift_decider/gear_cmd<br>/parameter_events<br>/rosout |
| /control/trajectory_follower/controller_node_exe | /localization/acceleration<br>/localization/kinematic_state<br>/parameter_events<br>/planning/scenario_planning/trajectory<br>/vehicle/status/steering_status | /control/trajectory_follower/control_cmd<br>/control/trajectory_follower/lateral/diagnostic<br>/control/trajectory_follower/lateral/predicted_trajectory<br>/control/trajectory_follower/longitudinal/diagnostic<br>/control/trajectory_follower/longitudinal/slope_angle<br>/diagnostics<br>/parameter_events<br>/rosout |
| /control/trajectory_follower/lane_departure_checker_node | /control/trajectory_follower/lateral/predicted_trajectory<br>/localization/kinematic_state<br>/map/vector_map<br>/parameter_events<br>/planning/mission_planning/route<br>/planning/scenario_planning/trajectory | /control/trajectory_follower/lane_departure_checker_node/debug/deviation/lateral<br>/control/trajectory_follower/lane_departure_checker_node/debug/deviation/yaw<br>/control/trajectory_follower/lane_departure_checker_node/debug/deviation/yaw_deg<br>/control/trajectory_follower/lane_departure_checker_node/debug/marker_array<br>/control/trajectory_follower/lane_departure_checker_node/debug/processing_time_ms<br>/diagnostics<br>/parameter_events<br>/rosout |
| /control/transform_listener_impl_5fb47c244120 | /parameter_events<br>/tf<br>/tf_static | /rosout |
| /control/vehicle_cmd_gate | /autoware/engage<br>/control/gate_mode_cmd<br>/control/shift_decider/gear_cmd<br>/control/trajectory_follower/control_cmd<br>/external/selected/control_cmd<br>/external/selected/gear_cmd<br>/external/selected/hazard_lights_cmd<br>/external/selected/heartbeat<br>/external/selected/turn_indicators_cmd<br>/parameter_events<br>/planning/hazard_lights_cmd<br>/planning/turn_indicators_cmd<br>/system/emergency/control_cmd<br>/system/emergency/gear_cmd<br>/system/emergency/hazard_lights_cmd<br>/system/fail_safe/mrm_state<br>/system/operation_mode/state<br>/vehicle/status/steering_status | /api/autoware/get/emergency<br>/api/autoware/get/engage<br>/control/command/control_cmd<br>/control/command/emergency_cmd<br>/control/command/gear_cmd<br>/control/command/hazard_lights_cmd<br>/control/command/turn_indicators_cmd<br>/control/current_gate_mode<br>/control/vehicle_cmd_gate/is_paused<br>/control/vehicle_cmd_gate/is_start_requested<br>/control/vehicle_cmd_gate/operation_mode<br>/diagnostics<br>/parameter_events<br>/rosout<br>/service_log |
| /default_ad_api/container | /parameter_events | /rosout |
| /default_ad_api/helpers/initial_pose_adaptor | /initialpose<br>/parameter_events | /parameter_events<br>/rosout<br>/service_log |
| /default_ad_api/helpers/routing_adaptor | /api/routing/state<br>/parameter_events<br>/planning/mission_planning/checkpoint<br>/planning/mission_planning/goal | /parameter_events<br>/rosout<br>/service_log |
| /default_ad_api/node/autoware_state | /api/localization/initialization_state<br>/api/operation_mode/state<br>/api/routing/state<br>/parameter_events<br>/system/component_state_monitor/component/launch/control<br>/system/component_state_monitor/component/launch/localization<br>/system/component_state_monitor/component/launch/map<br>/system/component_state_monitor/component/launch/perception<br>/system/component_state_monitor/component/launch/planning<br>/system/component_state_monitor/component/launch/sensing<br>/system/component_state_monitor/component/launch/system<br>/system/component_state_monitor/component/launch/vehicle | /autoware/state<br>/parameter_events<br>/rosout |
| /default_ad_api/node/fail_safe | /parameter_events<br>/system/fail_safe/mrm_state | /api/fail_safe/mrm_state<br>/parameter_events<br>/rosout |
| /default_ad_api/node/interface | /parameter_events | /parameter_events<br>/rosout<br>/service_log |
| /default_ad_api/node/localization | /localization/initialization_state<br>/parameter_events | /api/localization/initialization_state<br>/parameter_events<br>/rosout<br>/service_log |
| /default_ad_api/node/motion | /control/vehicle_cmd_gate/is_paused<br>/control/vehicle_cmd_gate/is_start_requested<br>/localization/kinematic_state<br>/parameter_events | /api/motion/state<br>/parameter_events<br>/rosout<br>/service_log |
| /default_ad_api/node/operation_mode | /parameter_events<br>/system/component_state_monitor/component/autonomous/control<br>/system/component_state_monitor/component/autonomous/localization<br>/system/component_state_monitor/component/autonomous/map<br>/system/component_state_monitor/component/autonomous/perception<br>/system/component_state_monitor/component/autonomous/planning<br>/system/component_state_monitor/component/autonomous/sensing<br>/system/component_state_monitor/component/autonomous/system<br>/system/component_state_monitor/component/autonomous/vehicle<br>/system/operation_mode/state | /api/operation_mode/state<br>/parameter_events<br>/rosout<br>/service_log |
| /default_ad_api/node/routing | /parameter_events<br>/planning/mission_planning/route<br>/planning/mission_planning/route_state<br>/system/operation_mode/state | /api/routing/route<br>/api/routing/state<br>/parameter_events<br>/rosout<br>/service_log |
| /launch_ros_34239 |  | /parameter_events<br>/rosout |
| /map/lanelet2_map_loader | /parameter_events | /map/vector_map<br>/parameter_events<br>/rosout |
| /map/lanelet2_map_visualization | /map/vector_map<br>/parameter_events | /map/vector_map_marker<br>/parameter_events<br>/rosout |
| /map/map_container | /parameter_events | /rosout |
| /map/map_hash_generator |  | /api/autoware/get/map/info/hash<br>/parameter_events<br>/rosout |
| /map/pointcloud_map_loader | /parameter_events | /map/pointcloud_map<br>/parameter_events<br>/rosout |
| /map/vector_map_tf_generator | /map/vector_map<br>/parameter_events | /parameter_events<br>/rosout<br>/tf_static |
| /map_height_fitter | /map/pointcloud_map<br>/parameter_events | /parameter_events<br>/rosout |
| /occupancy_grid_map/occupancy_grid_map_container | /parameter_events | /rosout |
| /occupancy_grid_map/occupancy_grid_map_node | /occupancy_grid_map/concatenated/pointcloud<br>/occupancy_grid_map/virtual_scan/laserscan<br>/parameter_events<br>/perception/obstacle_segmentation/pointcloud | /parameter_events<br>/perception/occupancy_grid_map/map<br>/rosout |
| /occupancy_grid_map/pointcloud_to_laserscan_node | /parameter_events<br>/perception/obstacle_segmentation/pointcloud | /occupancy_grid_map/virtual_scan/laserscan<br>/occupancy_grid_map/virtual_scan/pointcloud<br>/occupancy_grid_map/virtual_scan/ray<br>/occupancy_grid_map/virtual_scan/stixel<br>/parameter_events<br>/rosout |
| /occupancy_grid_map/transform_listener_impl_5bdf095408b0 | /parameter_events<br>/tf<br>/tf_static | /rosout |
| /occupancy_grid_map/transform_listener_impl_5bdf095b8110 | /parameter_events<br>/tf<br>/tf_static | /rosout |
| /perception/object_recognition/prediction/map_based_prediction | /map/vector_map<br>/parameter_events<br>/perception/object_recognition/tracking/objects | /parameter_events<br>/perception/object_recognition/objects<br>/perception/object_recognition/prediction/maneuver<br>/rosout |
| /perception/object_recognition/prediction/transform_listener_impl_5b384bfd0340 | /parameter_events<br>/tf<br>/tf_static | /rosout |
| /perception/object_recognition/tracking/multi_object_tracker | /parameter_events<br>/perception/object_recognition/detection/objects | /parameter_events<br>/perception/object_recognition/tracking/objects<br>/rosout |
| /perception/object_recognition/tracking/transform_listener_impl_6396b170ae28 | /parameter_events<br>/tf<br>/tf_static | /rosout |
| /planning/mission_planning/goal_pose_visualizer | /parameter_events<br>/planning/mission_planning/route | /parameter_events<br>/planning/mission_planning/echo_back_goal_pose<br>/rosout |
| /planning/mission_planning/mission_planner | /localization/kinematic_state<br>/map/vector_map<br>/parameter_events<br>/planning/scenario_planning/modified_goal | /parameter_events<br>/planning/mission_planning/route<br>/planning/mission_planning/route_marker<br>/planning/mission_planning/route_state<br>/rosout<br>/service_log |
| /planning/mission_planning/transform_listener_impl_5a7f2c64e748 | /parameter_events<br>/tf<br>/tf_static | /rosout |
| /planning/planning_diagnostics/planning_error_monitor | /parameter_events<br>/planning/scenario_planning/trajectory | /diagnostics<br>/parameter_events<br>/planning/planning_diagnostics/planning_error_monitor/debug/marker<br>/rosout |
| /planning/scenario_planning/external_velocity_limit_selector | /parameter_events<br>/planning/scenario_planning/clear_velocity_limit<br>/planning/scenario_planning/max_velocity_candidates<br>/planning/scenario_planning/max_velocity_default | /parameter_events<br>/planning/scenario_planning/max_velocity<br>/rosout |
| /planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner | /localization/acceleration<br>/localization/kinematic_state<br>/map/vector_map<br>/parameter_events<br>/perception/object_recognition/objects<br>/perception/occupancy_grid_map/map<br>/planning/mission_planning/route<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/input/lateral_offset<br>/planning/scenario_planning/scenario | /parameter_events<br>/planning/cooperate_status/avoidance_left<br>/planning/cooperate_status/avoidance_right<br>/planning/cooperate_status/lane_change_left<br>/planning/cooperate_status/lane_change_right<br>/planning/cooperate_status/pull_out<br>/planning/cooperate_status/pull_over<br>/planning/hazard_lights_cmd<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/debug/avoidance<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/debug/avoidance_debug_message_array<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/debug/lane_change_debug_message_array<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/debug/lanechange<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/debug/lanefollowing<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/debug/pullout<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/debug/pullover<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/debug/sideshift<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/drivable_area_boundary<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_path_planner/output/path_candidate<br>/planning/scenario_planning/lane_driving/behavior_planning/path_with_lane_id<br>/planning/scenario_planning/modified_goal<br>/planning/steering_factor/avoidance<br>/planning/steering_factor/intersection<br>/planning/steering_factor/lane_change<br>/planning/steering_factor/pull_out<br>/planning/steering_factor/pull_over<br>/planning/turn_indicators_cmd<br>/rosout |
| /planning/scenario_planning/lane_driving/behavior_planning/behavior_planning_container | /parameter_events | /rosout |
| /planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner | /awapi/tmp/virtual_traffic_light_states<br>/external/traffic_light_recognition/traffic_signals<br>/localization/acceleration<br>/localization/kinematic_state<br>/map/vector_map<br>/parameter_events<br>/perception/object_recognition/objects<br>/perception/obstacle_segmentation/pointcloud<br>/perception/occupancy_grid_map/map<br>/perception/traffic_light_recognition/traffic_signals<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/input/external_crosswalk_states<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/input/external_intersection_states<br>/planning/scenario_planning/lane_driving/behavior_planning/path_with_lane_id<br>/planning/scenario_planning/max_velocity_default | /parameter_events<br>/planning/cooperate_status/blind_spot<br>/planning/cooperate_status/crosswalk<br>/planning/cooperate_status/detection_area<br>/planning/cooperate_status/intersection<br>/planning/cooperate_status/no_stopping_area<br>/planning/cooperate_status/traffic_light<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/blind_spot<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/blind_spot/processing_time_ms<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/crosswalk<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/crosswalk/processing_time_ms<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/detection_area<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/detection_area/processing_time_ms<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/intersection<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/intersection/processing_time_ms<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/merge_from_private<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/merge_from_private/processing_time_ms<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/no_stopping_area<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/no_stopping_area/processing_time_ms<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/occlusion_spot<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/occlusion_spot/processing_time_ms<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/path<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/stop_line<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/stop_line/processing_time_ms<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/traffic_light<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/virtual_traffic_light<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/virtual_traffic_light/processing_time_ms<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/walkway<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/debug/walkway/processing_time_ms<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/output/stop_reason<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/blind_spot<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/crosswalk<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/detection_area<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/intersection<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/merge_from_private<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/no_stopping_area<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/occlusion_spot<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/stop_line<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/traffic_light<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/virtual_traffic_light<br>/planning/scenario_planning/lane_driving/behavior_planning/behavior_velocity_planner/virtual_wall/walkway<br>/planning/scenario_planning/lane_driving/behavior_planning/debug/traffic_signal<br>/planning/scenario_planning/lane_driving/behavior_planning/path<br>/planning/scenario_planning/status/infrastructure_commands<br>/planning/scenario_planning/status/stop_reasons<br>/rosout |
| /planning/scenario_planning/lane_driving/behavior_planning/rtc_auto_mode_manager | /parameter_events | /parameter_events<br>/rosout |
| /planning/scenario_planning/lane_driving/behavior_planning/transform_listener_impl_6490e70da3c0 | /parameter_events<br>/tf<br>/tf_static | /rosout |
| /planning/scenario_planning/lane_driving/behavior_planning/transform_listener_impl_70f92c5c72a8 | /parameter_events<br>/tf<br>/tf_static | /rosout |
| /planning/scenario_planning/lane_driving/motion_planning/motion_planning_container | /parameter_events | /rosout |
| /planning/scenario_planning/lane_driving/motion_planning/obstacle_avoidance_planner | /localization/kinematic_state<br>/parameter_events<br>/perception/object_recognition/objects<br>/planning/scenario_planning/lane_driving/behavior_planning/path<br>/planning/scenario_planning/lane_driving/obstacle_avoidance_approval | /parameter_events<br>/planning/scenario_planning/lane_driving/motion_planning/obstacle_avoidance_planner/debug/area_with_objects<br>/planning/scenario_planning/lane_driving/motion_planning/obstacle_avoidance_planner/debug/calculation_time<br>/plan


