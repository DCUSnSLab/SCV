
"use strict";

let GetTrafficLightStatus = require('./GetTrafficLightStatus.js');
let Lamps = require('./Lamps.js');
let ERP42Info = require('./ERP42Info.js');
let EgoDdVehicleStatus = require('./EgoDdVehicleStatus.js');
let SaveSensorData = require('./SaveSensorData.js');
let MultiEgoSetting = require('./MultiEgoSetting.js');
let EgoVehicleStatus = require('./EgoVehicleStatus.js');
let SyncModeSetGear = require('./SyncModeSetGear.js');
let MapSpec = require('./MapSpec.js');
let ScenarioLoad = require('./ScenarioLoad.js');
let SetTrafficLight = require('./SetTrafficLight.js');
let PRCtrlCmd = require('./PRCtrlCmd.js');
let SensorPosControl = require('./SensorPosControl.js');
let TrafficLight = require('./TrafficLight.js');
let CollisionData = require('./CollisionData.js');
let RadarDetections = require('./RadarDetections.js');
let RadarDetection = require('./RadarDetection.js');
let MoraiSrvResponse = require('./MoraiSrvResponse.js');
let SyncModeRemoveObject = require('./SyncModeRemoveObject.js');
let VehicleSpecIndex = require('./VehicleSpecIndex.js');
let CtrlCmd = require('./CtrlCmd.js');
let WaitForTickResponse = require('./WaitForTickResponse.js');
let GPSMessage = require('./GPSMessage.js');
let NpcGhostCmd = require('./NpcGhostCmd.js');
let VehicleSpec = require('./VehicleSpec.js');
let SyncModeResultResponse = require('./SyncModeResultResponse.js');
let SyncModeInfo = require('./SyncModeInfo.js');
let MoraiSimProcHandle = require('./MoraiSimProcHandle.js');
let ObjectStatus = require('./ObjectStatus.js');
let SyncModeCmdResponse = require('./SyncModeCmdResponse.js');
let VehicleCollisionData = require('./VehicleCollisionData.js');
let MoraiSimProcStatus = require('./MoraiSimProcStatus.js');
let SyncModeScenarioLoad = require('./SyncModeScenarioLoad.js');
let MapSpecIndex = require('./MapSpecIndex.js');
let GhostMessage = require('./GhostMessage.js');
let EventInfo = require('./EventInfo.js');
let IntersectionControl = require('./IntersectionControl.js');
let PRStatus = require('./PRStatus.js');
let ObjectStatusList = require('./ObjectStatusList.js');
let MoraiTLInfo = require('./MoraiTLInfo.js');
let VehicleCollision = require('./VehicleCollision.js');
let MoraiTLIndex = require('./MoraiTLIndex.js');
let DdCtrlCmd = require('./DdCtrlCmd.js');
let SyncModeAddObject = require('./SyncModeAddObject.js');
let PREvent = require('./PREvent.js');
let SyncModeCmd = require('./SyncModeCmd.js');
let IntscnTL = require('./IntscnTL.js');
let ReplayInfo = require('./ReplayInfo.js');
let SyncModeCtrlCmd = require('./SyncModeCtrlCmd.js');
let IntersectionStatus = require('./IntersectionStatus.js');
let NpcGhostInfo = require('./NpcGhostInfo.js');
let WaitForTick = require('./WaitForTick.js');

module.exports = {
  GetTrafficLightStatus: GetTrafficLightStatus,
  Lamps: Lamps,
  ERP42Info: ERP42Info,
  EgoDdVehicleStatus: EgoDdVehicleStatus,
  SaveSensorData: SaveSensorData,
  MultiEgoSetting: MultiEgoSetting,
  EgoVehicleStatus: EgoVehicleStatus,
  SyncModeSetGear: SyncModeSetGear,
  MapSpec: MapSpec,
  ScenarioLoad: ScenarioLoad,
  SetTrafficLight: SetTrafficLight,
  PRCtrlCmd: PRCtrlCmd,
  SensorPosControl: SensorPosControl,
  TrafficLight: TrafficLight,
  CollisionData: CollisionData,
  RadarDetections: RadarDetections,
  RadarDetection: RadarDetection,
  MoraiSrvResponse: MoraiSrvResponse,
  SyncModeRemoveObject: SyncModeRemoveObject,
  VehicleSpecIndex: VehicleSpecIndex,
  CtrlCmd: CtrlCmd,
  WaitForTickResponse: WaitForTickResponse,
  GPSMessage: GPSMessage,
  NpcGhostCmd: NpcGhostCmd,
  VehicleSpec: VehicleSpec,
  SyncModeResultResponse: SyncModeResultResponse,
  SyncModeInfo: SyncModeInfo,
  MoraiSimProcHandle: MoraiSimProcHandle,
  ObjectStatus: ObjectStatus,
  SyncModeCmdResponse: SyncModeCmdResponse,
  VehicleCollisionData: VehicleCollisionData,
  MoraiSimProcStatus: MoraiSimProcStatus,
  SyncModeScenarioLoad: SyncModeScenarioLoad,
  MapSpecIndex: MapSpecIndex,
  GhostMessage: GhostMessage,
  EventInfo: EventInfo,
  IntersectionControl: IntersectionControl,
  PRStatus: PRStatus,
  ObjectStatusList: ObjectStatusList,
  MoraiTLInfo: MoraiTLInfo,
  VehicleCollision: VehicleCollision,
  MoraiTLIndex: MoraiTLIndex,
  DdCtrlCmd: DdCtrlCmd,
  SyncModeAddObject: SyncModeAddObject,
  PREvent: PREvent,
  SyncModeCmd: SyncModeCmd,
  IntscnTL: IntscnTL,
  ReplayInfo: ReplayInfo,
  SyncModeCtrlCmd: SyncModeCtrlCmd,
  IntersectionStatus: IntersectionStatus,
  NpcGhostInfo: NpcGhostInfo,
  WaitForTick: WaitForTick,
};
