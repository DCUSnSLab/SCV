# One segment of an OSM way between two consecutive nodes. Tags are the way's tags.
int64 way_id
int64 from_id
int64 to_id
float64 length
diagnostic_msgs/KeyValue[] tags
